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

namespace tinylink {
	class TL_TCP
	{
		public:
			bool init(int type, int port, const char* ip);
			bool init(int type);
			TL_TCP Accept();
			bool Connect(const char* ip, int port);
			int write(const char* message);
			int read(char *buffer, int len);
			int Close();
			bool isConnected();
			int conn_state=0;
		private:
			bool init(int type, int socket_fd);
			int fd;
			int _type;
			struct sockaddr_in server_addr;
			struct sockaddr_in client_addr;			
			int queue=5;
	};
}

typedef tinylink::TL_TCP TL_TCP;
#endif

