#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <unistd.h>  
#include <sys/socket.h>  
#include <netinet/in.h>  
#include <arpa/inet.h>  
#include <netinet/in.h>  
#include <sys/socket.h>  
#include <time.h> 
#include <cstring>
#include <stdio.h>
 
 
#define  MAXLINE 100   
 
int main(int argc, char ** argv) {
	pid_t pp = fork();
	if (pp == 0) {
		unsigned short port = 9997;
		unsigned short port2 = 9995;
	
		//socket
		int accept_fd = ::socket(AF_INET, SOCK_STREAM | SOCK_CLOEXEC, IPPROTO_TCP); //创建socket，文件描述符是accept_fd
		int accept_fd2 = ::socket(AF_INET, SOCK_STREAM | SOCK_CLOEXEC, IPPROTO_TCP); //创建socket，文件描述符是accept_fd
 
 
		//端口重用，快速重启服务
		int opt = 1;
		::setsockopt(accept_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof (opt)); //accept_fd套接字描述符/ SO_REUSEADDR，打开或关闭地址复用功能。/
		::setsockopt(accept_fd2, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof (opt)); //accept_fd套接字描述符/ SO_REUSEADDR，打开或关闭地址复用功能。/
        ::setsockopt(accept_fd, SOL_SOCKET, SO_REUSEPORT, &opt, sizeof (opt)); //accept_fd套接字描述符/ SO_REUSEADDR，打开或关闭地址复用功能。/
		::setsockopt(accept_fd2, SOL_SOCKET, SO_REUSEPORT, &opt, sizeof (opt)); //accept_fd套接字描述符/ SO_REUSEADDR，打开或关闭地址复用功能。/
 
		//bind
		sockaddr_in addr;
		memset(&addr, 0, sizeof (sockaddr_in));
		addr.sin_family = AF_INET; //选择 AF_INET 的目的就是使用 IPv4 进行通信。因为 IPv4 使用 32 位地址
		addr.sin_port = htons(port); //inet_pton：将“点分十进制” －> “二进制整数”
		::inet_pton(AF_INET, "192.168.23.232", &addr.sin_addr); //bind()函数把一个地址族中的特定地址赋给socket。例如对应AF_INET、AF_INET6就是把一个ipv4或ipv6地址和端口号组合赋给socket。
 
		sockaddr_in addr2;
		memset(&addr2, 0, sizeof (sockaddr_in));
		addr2.sin_family = AF_INET; //选择 AF_INET 的目的就是使用 IPv4 进行通信。因为 IPv4 使用 32 位地址
		addr2.sin_port = htons(port2); //inet_pton：将“点分十进制” －> “二进制整数”
		::inet_pton(AF_INET, "192.168.23.232", &addr2.sin_addr); //bind()函数把一个地址族中的特定地址赋给socket。例如对应AF_INET、AF_INET6就是把一个ipv4或ipv6地址和端口号组合赋给socket。
 
	
		if (0 != ::bind(accept_fd, (sockaddr*) & addr, (socklen_t)sizeof (sockaddr_in)))//即socket描述字，它是通过socket()函数创建了，唯一标识一个socket。bind()函数就是将给这个描述字绑定一个名字。
		{//addr：一个const struct sockaddr *指针，指向要绑定给sockfd的协议地址。这个地址结构根据地址创建socket时的地址协议族的不同而不同（IPV4/6）
			perror("bind 1failed"); //通常服务器端在listen之前会调用bind()，而客户端就不会调用，而是在connect()时由系统随机生成一个。
			return false;
		}
 
		if (0 != ::bind(accept_fd2, (sockaddr*) & addr, (socklen_t)sizeof (sockaddr_in)))//即socket描述字，它是通过socket()函数创建了，唯一标识一个socket。bind()函数就是将给这个描述字绑定一个名字。
		{//addr：一个const struct sockaddr *指针，指向要绑定给sockfd的协议地址。这个地址结构根据地址创建socket时的地址协议族的不同而不同（IPV4/6）
			perror("bind1 failed"); //通常服务器端在listen之前会调用bind()，而客户端就不会调用，而是在connect()时由系统随机生成一个。
			return false;
		}
		pid_t p1 = fork();
		if (p1 == 0) {
 
			if (0 != ::listen(accept_fd, SOMAXCONN)) //要监听的描述字，最大连接数。listen是被动的，等待客户的请求。
			{
				perror("listen failed");
				return false;
			}
			printf("lisen 2885 port  ok\n");
			
			socklen_t addrlen = (socklen_t)sizeof (addr);
			while (1) {
				memset(&addr, 0, sizeof (sockaddr_in));
				int client_fd = ::accept(accept_fd, (sockaddr*) & addr, &addrlen);
				char* a = inet_ntoa(addr.sin_addr);
				printf("accept,%d,%s,%d\n", client_fd, a, addr.sin_port);
				//失败
 
				if (client_fd < 0)
					printf("not ok\n");
			}
 
 
			sleep(10);
		} else {
 
			sleep(3);
			//printf("gogogo1\n");
			//连接
 
			int ret = ::connect(accept_fd2, (sockaddr*) & addr2, (socklen_t)sizeof (sockaddr_in));
			char* a = inet_ntoa(addr2.sin_addr);
			printf(" connect 2855 ret =%d,%hu,%s\n", ret, addr2.sin_port, a);//9995
		}
		sleep(10);
		close(accept_fd2);
		close(accept_fd);
	} else {
		unsigned short port = 9995;
		unsigned short port2 = 9997;
		unsigned short port3 = 9996;
		//socket
		int accept_fd = ::socket(AF_INET, SOCK_STREAM | SOCK_CLOEXEC, IPPROTO_TCP); //创建socket，文件描述符是accept_fd
		int accept_fd2 = ::socket(AF_INET, SOCK_STREAM | SOCK_CLOEXEC, IPPROTO_TCP); //创建socket，文件描述符是accept_fd
 
		//端口重用，快速重启服务
		int opt = 1;
		::setsockopt(accept_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof (opt)); //accept_fd套接字描述符/ SO_REUSEADDR，打开或关闭地址复用功能。/
		::setsockopt(accept_fd2, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof (opt)); //accept_fd套接字描述符/ SO_REUSEADDR，打开或关闭地址复用功能。/
	    ::setsockopt(accept_fd, SOL_SOCKET, SO_REUSEPORT, &opt, sizeof (opt)); //accept_fd套接字描述符/ SO_REUSEADDR，打开或关闭地址复用功能。/
		::setsockopt(accept_fd2, SOL_SOCKET, SO_REUSEPORT, &opt, sizeof (opt)); //accept_fd套接字描述符/ SO_REUSEADDR，打开或关闭地址复用功能。/
 
 
		//bind
		sockaddr_in addr;
		memset(&addr, 0, sizeof (sockaddr_in));
		addr.sin_family = AF_INET; //选择 AF_INET 的目的就是使用 IPv4 进行通信。因为 IPv4 使用 32 位地址
		addr.sin_port = htons(port); //inet_pton：将“点分十进制” －> “二进制整数”
		::inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr); //bind()函数把一个地址族中的特定地址赋给socket。例如对应AF_INET、AF_INET6就是把一个ipv4或ipv6地址和端口号组合赋给socket。
 
		sockaddr_in addr2;
		memset(&addr2, 0, sizeof (sockaddr_in));
		addr2.sin_family = AF_INET; //选择 AF_INET 的目的就是使用 IPv4 进行通信。因为 IPv4 使用 32 位地址
		addr2.sin_port = htons(port2); //inet_pton：将“点分十进制” －> “二进制整数”
		::inet_pton(AF_INET, "127.0.0.1", &addr2.sin_addr); //bind()函数把一个地址族中的特定地址赋给socket。例如对应AF_INET、AF_INET6就是把一个ipv4或ipv6地址和端口号组合赋给socket。
 
		sockaddr_in addr3;
		memset(&addr3, 0, sizeof (sockaddr_in));
		addr3.sin_family = AF_INET; //选择 AF_INET 的目的就是使用 IPv4 进行通信。因为 IPv4 使用 32 位地址
		addr3.sin_port = htons(port3); //inet_pton：将“点分十进制” －> “二进制整数”
		::inet_pton(AF_INET, "127.0.0.1", &addr3.sin_addr); //bind()函数把一个地址族中的特定地址赋给socket。例如对应AF_INET、AF_INET6就是把一个ipv4或ipv6地址和端口号组合赋给socket。
 
		if (0 != ::bind(accept_fd, (sockaddr*) & addr, (socklen_t)sizeof (sockaddr_in)))//即socket描述字，它是通过socket()函数创建了，唯一标识一个socket。bind()函数就是将给这个描述字绑定一个名字。
		{//addr：一个const struct sockaddr *指针，指向要绑定给sockfd的协议地址。这个地址结构根据地址创建socket时的地址协议族的不同而不同（IPV4/6）
			perror("bind 2failed"); //通常服务器端在listen之前会调用bind()，而客户端就不会调用，而是在connect()时由系统随机生成一个。
			return false;
		}
 
		if (0 != ::bind(accept_fd2, (sockaddr*) & addr3, (socklen_t)sizeof (sockaddr_in)))//即socket描述字，它是通过socket()函数创建了，唯一标识一个socket。bind()函数就是将给这个描述字绑定一个名字。
		{//addr：一个const struct sockaddr *指针，指向要绑定给sockfd的协议地址。这个地址结构根据地址创建socket时的地址协议族的不同而不同（IPV4/6）
			perror("bind 2failed"); //通常服务器端在listen之前会调用bind()，而客户端就不会调用，而是在connect()时由系统随机生成一个。
			return false;
		}
		pid_t p = fork();
		if (p == 0) {
			if (0 != ::listen(accept_fd, SOMAXCONN)) //要监听的描述字，最大连接数。listen是被动的，等待客户的请求。
			{
				perror("listen failed");
				return false;
			}
			printf("lisen 3367 port  ok\n");
			socklen_t addrlen = (socklen_t)sizeof (addr);
			
			while (1) {
				memset(&addr, 0, sizeof (sockaddr_in));
				int client_fd = ::accept(accept_fd, (sockaddr*) & addr, &addrlen);
				char* a = inet_ntoa(addr.sin_addr);
				printf("accept,%d,%s,%d\n", client_fd, a, addr.sin_port);
				//失败
 
				if (client_fd < 0)
					printf("not ok\n");
			}
			sleep(10);
		} else {
 
			sleep(3);
		
			int ret = ::connect(accept_fd2, (sockaddr*) & addr2, (socklen_t)sizeof (sockaddr_in));
			char* a = inet_ntoa(addr2.sin_addr);
			printf(" connect 3367 ret =%d,%hu,%s\n", ret, addr2.sin_port, a);
		}
		sleep(10);
		close(accept_fd2);
		close(accept_fd);
	}
 
}
