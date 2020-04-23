#include <iostream>
#include <string>
#include <sys/types.h>       
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

/* 服务器端步骤分析
 * 1. socket(AF_INET,SOCK_STREAM,0)
 * 2. bind(serv_sock,(struct sockaddr*)&serv_sock,sizeof(serv_addr)
 * 3. listen(serv_sock,SOMAXCONN)
 * 4. accept(serv_sock,(struct sockaddr*)&client_addr,&client_addr_len)
 * 5. read、write函数进行数据的发送和接收
 * 函数参考网址: http://man7.org/linux/man-pages/man2
*/
int main(int argc,char** argv){
	int serv_sock,client_sock;
	sockaddr_in serv_addr,client_addr;
	char message[] = "hello world";

	serv_sock = socket(AF_INET,SOCK_STREAM,0);
	if (serv_sock == -1){
		std::cout <<"create socket failed" << std::endl;
	}

	memset(&serv_addr,0,sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(9190);
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(serv_sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr)) == -1){
		std::cout <<"bind socket failed" << std::endl;
	}
	
	
	if(listen(serv_sock,SOMAXCONN) == -1){
		std::cout <<"listen socket failed" << std::endl;
	}

	socklen_t client_addr_len = sizeof(client_addr);
	client_sock = accept(serv_sock,(struct sockaddr*)&client_addr,&client_addr_len);
	if (client_sock == -1){
		std::cout <<"accept socket failed" << std::endl;
	}
	
	write(client_sock,message,sizeof(message));

	close(serv_sock);
	close(client_sock);

	return 0;
}
