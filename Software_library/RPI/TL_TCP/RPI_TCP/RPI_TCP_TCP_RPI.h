#ifndef RPI_TCP_TCP_RPI_H
#define RPI_TCP_TCP_RPI_H
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <iostream>
#include "WString.h"

namespace tinylink {
	class TL_TCP
	{
		public:
			bool init(int type, const char* ip, int port);
			TL_TCP Accept();
			int Connect(const char* ip, int port);
			ssize_t write(const String* message);
			ssize_t read(String* message);
			int Close();
			operator bool();
		private:
			bool init(int type, int socket_fd);
			int fd=-1;
			int _type=-1;
			struct sockaddr_in server_addr;
			struct sockaddr_in client_addr;			
			int queue=5;
	};
}


typedef tinylink::TL_TCP TL_TCP;
#endif
