#include <iostream>
#include <string>
#include <sys/types.h>       
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

/* 步骤分析
 * 1: socket(PF_INET,SOCK_STREAM,0)
 * 2: connect(serv_sock,(sockaddr*)&serv_addr,sizeof(serv_addr)
 * 3: read、write函数进行数据通信
*/

int main(int argc,char** argv) {
    int serv_sock;
    char message[30];
    int str_len = 0;

    serv_sock = socket(PF_INET,SOCK_STREAM,0);
    if (serv_sock == -1){
        std::cout << "create socket failed" << std::endl;
    }
    
    sockaddr_in serv_addr;
    memset(&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));
    
    if (connect(serv_sock,(sockaddr*)&serv_addr,sizeof(serv_addr)) == -1){
        std::cout << "connet socket failed" << std::endl;
    }
    
    while (1){
        str_len = recv(serv_sock,message,sizeof(message),MSG_PEEK|MSG_DONTWAIT);
        if (str_len > 0){
            std::cout << "recv data." << std::endl;
            break;
        }
        std::cout <<"begin to sleep 10S." << std::endl;
        sleep(10);
    }
    
    str_len = read(serv_sock,message,sizeof(message));
    if (str_len == -1){
        std::cout << "read socket failed." << std::endl;
    }
    std::cout <<"recv message: " << message << std::endl;

    close(serv_sock);
    
    return 0;
}