#include <iostream>
#include <string>
#include <sys/types.h>       
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#define BUF_SIZE 30

int main(int argc,char** argv){
	int serv_sock = socket(PF_INET,SOCK_STREAM,0);
	if (serv_sock == -1){
		std::cout <<"create socket falled." << std::endl;
	}
	
	int option = true;
	socklen_t option_len = sizeof(option);
	int state = setsockopt(serv_sock,SOL_SOCKET,SO_REUSEADDR,&option,option_len);
	if (state == -1){
		std::cout <<"set socket REUSEADDR failed." << std::endl;
	}
	
	sockaddr_in serv_addr;
	memset(&serv_addr,0,sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	// 注: 若IP为字符串，则使用inet_addr函数进行转换
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(9190);
	if(bind(serv_sock,(sockaddr*)&serv_addr,sizeof(serv_addr)) == -1){
		std::cout <<"bind socket failed." << std::endl;
	}
	
	if(listen(serv_sock,SOMAXCONN) == -1){
		std::cout <<"listen socket falled." << std::endl;
	}

	int client_sock;
	sockaddr_in clientAddr;
	socklen_t clientAddrLen = sizeof(clientAddr);

	client_sock = accept(serv_sock,(sockaddr*)&clientAddr,&clientAddrLen);
	if (client_sock == -1){
		std::cout <<"accept socket failed." << std::endl;
	}
	
	FILE* fp = fopen("readme.txt","rb");
	char buf[BUF_SIZE] = {0};
	int readCnt = 0;
	while (1){
		// 清空读取数组中所有的元素
		memset(buf,0,BUF_SIZE);
		readCnt = fread(buf,1,BUF_SIZE,fp);
		// 若if条件为真,则表明读取完文件
		if (readCnt < BUF_SIZE){
			write(client_sock,buf,readCnt);
			break;
		}
		write(client_sock,buf,BUF_SIZE);
	}

	memset(buf,0,BUF_SIZE);
	// 关闭写入流，此时会向客户端发送EOF标记
	shutdown(client_sock,SHUT_WR);
	read(client_sock,buf,BUF_SIZE);
	std::cout <<"recv message: " << buf << std::endl;

	fclose(fp);
	close(client_sock);
	close(serv_sock);
	return 0;
}