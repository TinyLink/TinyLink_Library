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
			TL_TCP();			
			bool Init(int type, const char* ip="", int port=0);
			TL_TCP Accept();
			int Connect(const char* ip, int port);
			ssize_t Write(const String& message);
			ssize_t Read(String& message);
			int Close();
			operator bool();
	
		private:
			bool Init(int type, int socket_fd);
			int fd;
			int _type;			
	};
}


typedef tinylink::TL_TCP TL_TCP;
#endif
