#include"RPI_TCP_TCP_RPI.h"
#include<stdio.h>  
#include<sys/types.h>  
#include<sys/socket.h>  
#include<stdlib.h>  
#include<netinet/in.h>  
#include<arpa/inet.h>

namespace tinylink {
	bool TL_TCP::init(int type, int port, const char* ip)
		{	
		   _type = type;
		   if(_type!=0)
		   {
			std::cout<<"wrong init type 1 for client, 0 for server!"<<std::endl;
			return false;
		   }
		   fd = socket(AF_INET, SOCK_STREAM, 0);//set fd kind of IPV4 sock_stream
		
    		   memset(&server_addr, 0, sizeof(server_addr));
    		   server_addr.sin_family = AF_INET;
    		   server_addr.sin_port = htons(port);  ///set server port
		   
		   if(strlen(ip)==0)
		   server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
		   else
		   server_addr.sin_addr.s_addr = inet_addr(ip);//set server ip
		
		   if(bind(fd, (struct sockaddr*)&server_addr, sizeof(server_addr))==-1)
		   {
			std::cout<<"tcp server bind fault"<<std::endl;
			return false; 
		   }
		   if(listen(fd, queue)==-1)
		   {
			std::cout<<"tcp server listen fault"<<std::endl;
			return false;
		   }
		   return true;
		}

	bool TL_TCP::init(int type)
		{ 
		  _type = type;

		  if(_type!=1)
		  return false;

		  fd = socket(AF_INET, SOCK_STREAM, 0);//set fd kind of IPV4 sock_stream
		  return true;
		}

	bool TL_TCP::init(int type, int socket_fd)
		{
		  _type = type;
		  
		  if(_type!=2)
		  return false;

		  fd = socket_fd;
		  conn_state = 1;
 		  return true;
		}

	TL_TCP	TL_TCP::Accept()
			{
			   int connect_fd;
			   unsigned int len = sizeof(client_addr);
			   connect_fd=accept(fd, (struct sockaddr*)&client_addr, &len);
			   
			   if(connect_fd<0)
				std::cout<<"accept fault"<<std::endl;
			   else
				conn_state=1;

			   TL_TCP conn_sock;
			   conn_sock.init(2,connect_fd);

			   return conn_sock;
			}

	bool TL_TCP::Connect(const char* ip, int port)
			{
			   memset(&server_addr, 0, sizeof(server_addr));
	                   unsigned int len = sizeof(server_addr);
				
			   server_addr.sin_family = AF_INET;
        	           server_addr.sin_port = htons(port);  //set connect server port
                	   server_addr.sin_addr.s_addr = inet_addr(ip);//set connect server ip like"127.0.0.1"

			   if (connect(fd, (struct sockaddr *)&server_addr, len) < 0)
    				{
				   std::cout<<"client connect fault"<<std::endl;
				   return false;
    				}
			   else 
				{
				conn_state=1;
				return true;
				}	
			}
	int TL_TCP::write(const char* message)
		{
		   return send(fd, message, strlen(message), 0);
		}

	int TL_TCP::read(char *buffer, int len)
		{
		   return recv(fd, buffer, len, 0);
		}

	int TL_TCP::Close()
		{
		   close(fd);
		   conn_state=0;
		}

	bool TL_TCP::isConnected()
		{
		   if(conn_state==0)
			return false;
		   else
			return true;
		}

}
