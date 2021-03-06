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
    sockaddr_in serv_addr;
    serv_sock = socket(PF_INET,SOCK_STREAM,0);
    memset(&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    if(connect(serv_sock,(sockaddr*)&serv_addr,sizeof(serv_addr)) == -1){
        std::cout << "connet socket failed." << std::endl;
    }

    char message[30] = {0};
    int cnt = 0;
    int str_len = 0;
    unsigned long length = 0;
    read(serv_sock,(char*)&length,sizeof(length));
    length = ntohl(length);
    std::cout << "recv length: " << length << std::endl;
    // 读取到数据后，将数据原样进行返回
    str_len = read(serv_sock,message,length);
    if (str_len == -1){
        std::cout <<"read socket falled." << std::endl;
    }
    std::cout <<"recv message: " << message << std::endl;

    close(serv_sock);
    return 0;
}