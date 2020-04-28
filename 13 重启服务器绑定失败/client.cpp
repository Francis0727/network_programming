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

#define BUFSIZE 30

int main(int argc,char** argv) {
    int serv_sock;
    sockaddr_in serv_addr;
    serv_sock = socket(PF_INET,SOCK_STREAM,0);
    memset(&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    if(connect(serv_sock,(sockaddr*)&serv_addr,sizeof(serv_addr)) == -1){
        std::cout << "connet socket failed." << std::endl;
    }

    FILE* fp = fopen("back.txt","wb");
    char message[BUFSIZE] = {0};
    int readCnt = 0;
    
    while ((readCnt = read(serv_sock,message,BUFSIZE)) != 0){
        if (readCnt == -1){
            std::cout <<"read socket failed." << std::endl;
            break;
        }
        fwrite(message,1,readCnt,fp);
    }
    std::cout <<"received file data." << std::endl;
    write(serv_sock,"Thanks you",10);
    close(serv_sock);
    return 0;
}