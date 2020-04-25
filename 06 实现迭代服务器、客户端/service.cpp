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
	int serv_sock = socket(PF_INET,SOCK_STREAM,0);
	if (serv_sock == -1){
		std::cout <<"create socket falled." << std::endl;
	}
	
	sockaddr_in serv_addr;
	memset(&serv_addr,0,sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	// 注: 若IP为字符串，则使用inet_addr函数进行转换
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));
	if(bind(serv_sock,(sockaddr*)&serv_addr,sizeof(serv_addr)) == -1){
		std::cout <<"bind socket failed." << std::endl;
	}
	
	if(listen(serv_sock,SOMAXCONN) == -1){
		std::cout <<"listen socket falled." << std::endl;
	}

	int client_sock;
	sockaddr_in clientAddr;
	socklen_t clientAddrLen = sizeof(clientAddr);
	for(int cnt = 0; cnt < 5;++cnt) {
		client_sock = accept(serv_sock,(sockaddr*)&clientAddr,&clientAddrLen);
		if (client_sock == -1){
			std::cout <<"accept socket failed." << std::endl;
		}
		char str1[] = "hello world.";
		char str2[30];   // 用于接收发送到的字符串
		std::cout <<"send message: " << str1 << std::endl;
		write(client_sock,str1,sizeof(str1));
		memset(str2,0,sizeof(str2));
		read(client_sock,str2,sizeof(str2));
		std::cout <<"recv message: " << str2 << std::endl;
		close(client_sock);
	}
	
	close(serv_sock);
	return 0;
}