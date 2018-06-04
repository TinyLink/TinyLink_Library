#include"RPI_TCP_TCP_RPI.h"



namespace tinylink {
	    TL_TCP::TL_TCP(void):_type(-1),fd(-1){}

	bool TL_TCP::init(int type, const char* ip, int port)
		{	
		   if(_type!=-1)	//can not repeated initialization
			return false;

		   _type = type;
		   struct sockaddr_in server_addr;
		   struct sockaddr_in client_addr;
		   int queue = 5;

		   switch(_type){
		   	case 0:
				if(port!=0){
					fd = socket(AF_INET, SOCK_STREAM, 0);//set fd kind of IPV4 sock_stream

        	                	memset(&server_addr, 0, sizeof(server_addr));
   	       				server_addr.sin_family = AF_INET;  //set ipv4
					server_addr.sin_port = htons(port);  ///set server port

					if(strlen(ip)==0)
                        		server_addr.sin_addr.s_addr = htonl(INADDR_ANY);//set server ip any
                        		else
                        		server_addr.sin_addr.s_addr = inet_addr(ip);//set server ip

                        		if(bind(fd, (struct sockaddr*)&server_addr, sizeof(server_addr))==-1){
                                	//	std::cout<<"tcp server bind fault"<<endl;
                                		return false;
                        			}
                        		if(listen(fd, queue)==-1){
                                	//	std::cout<<"tcp server listen fault"<<endl;
                                		return false;
                        			}
                        		return true;
					}
				else{
					//	std::cout<<"please set a port for server"<<endl;
		                        return false;
					}
			case 1:
				fd = socket(AF_INET, SOCK_STREAM, 0);//set fd kind of IPV4 sock_stream
                        	memset(&client_addr, 0, sizeof(client_addr));
                        	client_addr.sin_family = AF_INET;  //set ipv4
                        	client_addr.sin_port = htons(port);  ///set client port

                        	if(strlen(ip)==0)
	                        client_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	                        else
	                        client_addr.sin_addr.s_addr = inet_addr(ip);//set client ip

	                        if(bind(fd, (struct sockaddr*)&client_addr, sizeof(client_addr))==-1){
	                               //	std::cout<<"tcp client bind fault"<<endl;
	                                return false;
	                        	}
	
	                        return true;

			default :
				return false;
			}
		}

	bool TL_TCP::init(int type, int socket_fd)
		{
		  _type = type;
		  
		  if(_type!=2)
		  return false;

		  fd = socket_fd;
 		  return true;
		}

	TL_TCP	TL_TCP::accept()
			{
			   if(_type!=0){
			  //	std::cout<<"only server type can accept!"<<endl;
			   	connect_fd = -1;
			   }
			   else{
				int connect_fd;
                           	TL_TCP conn_sock;
                           	struct sockaddr_in client_addr;
			   	unsigned int len = sizeof(client_addr);
			   	connect_fd=::accept(fd, (struct sockaddr*)&client_addr, &len);
			   }

			   conn_sock.init(2,connect_fd);

			   return conn_sock;
			}

	int TL_TCP::connect(const char* ip, int port)
			{
			   if(_type!=1){
			   //	std::cout<<"only client type could connect!"<<endl;
				return -1;
			   }

			   struct sockaddr_in server_addr;
			   memset(&server_addr, 0, sizeof(server_addr));
	                   unsigned int len = sizeof(server_addr);
				
			   server_addr.sin_family = AF_INET;
        	           server_addr.sin_port = htons(port);  //set connect server port
                	   server_addr.sin_addr.s_addr = inet_addr(ip);//set connect server ip like"192.168.199.197"

			   return ::connect(fd, (struct sockaddr *)&server_addr, len);
			}

	ssize_t TL_TCP::write(const String& message)
		{
		   if(_type==1||_type==2&&fd>0)
		   return send(fd, message.c_str(), message.length(), 0);
		   else
		   return -1;
		}

	ssize_t TL_TCP::read(String& message)
		{
		   if(_type==1||_type==2&&fd>0)
                   {
		   char buffer[1024];
		   ssize_t len = recv(fd, buffer, 1024, 0);
		   buffer[len] = 0;
		   message=buffer;
		   return len;
		   }
		   else
		   return -1;
		}

	int TL_TCP::close()
		{
		   if(::close(fd)==0){
		  	fd=-1;
			_type=-1;
			return 0;
			}
		   else
		   return -1;
		}
	TL_TCP::operator bool()
		{
		   if(fd<0)
		   return false;
		   else
		   return true;
		}

}
