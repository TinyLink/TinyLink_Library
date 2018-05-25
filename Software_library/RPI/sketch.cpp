
#include "TL_Libraries.h"

TL_TCP client;
TL_TCP server = TL_WiFi.fetchTCP();
void setup(){
	server.init(0, 8888, "192.168.199.197");
}
void loop(){
	if(client.isConnected()){
                String message;
		message = client.read();
		std::cout<<message<<"that's message"<<endl;

                if(message=="forward"){
			TL_Car.moveForward();
			std::cout<<message<<endl;
                }else if(message=="back"){
			TL_Car.moveBack();
			std::cout<<message<<endl;
		}else if(message=="left"){
			TL_Car.turnLeft();
			std::cout<<message<<endl;
		}else if(message=="right"){
			TL_Car.turnRight();
			std::cout<<message<<endl;
		}else if(message=="stop"){
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

	
