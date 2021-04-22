#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <unistd.h>  
#include <sys/socket.h>  
#include <netinet/in.h>  
#include <arpa/inet.h>  
#include<netinet/in.h>  
#include<sys/socket.h>  
#include<time.h> 
#include<cstring>
#include<stdio.h>

#define MAXLINE 100

int main(int argc, char **argv) {
	pid_t pp = fork();
	if(pp == 0) {
		unsigned short port = 9997;
		unsigned short port2 = 9995;

		// socket
		int accept_fd = ::socket(AF_INET, SOCK_STREAM | SOCK_CLOEXEC, IPPROTO_TCP);
	}
}
