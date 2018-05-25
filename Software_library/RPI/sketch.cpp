
#include "TL_Libraries.h"

TL_TCP client;
TL_TCP server = TL_WiFi.fetchTCP();
void setup(){
	server.init(0, 8888, "192.168.199.197");
}
void loop(){
	if(client.isConnected()){
                char message[50];
		memset(message, 0, sizeof(message));
		client.read(message, 50);
		std::cout<<message<<"that's message"<<endl;

                if(strcmp(message,"forward")==0){
			TL_Car.moveForward();
			std::cout<<message<<endl;
                }else if(strcmp( message,"back")==0){
			TL_Car.moveBack();
			std::cout<<message<<endl;
		}else if(strcmp( message,"left")==0){
			TL_Car.turnLeft();
			std::cout<<message<<endl;
		}else if(strcmp( message,"right")==0){
			TL_Car.turnRight();
			std::cout<<message<<endl;
		}else if(strcmp( message,"stop")==0){
                        TL_Car.stop();
			std::cout<<message<<endl;
                }
		client.Close();
                        client.Close();
	}
	else
	{
	std::cout<<"reconnect"<<endl;
	client = server.Accept();
	}
}

	
