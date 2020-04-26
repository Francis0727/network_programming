#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <iostream>

int main(int argc, char *argv[]){
    int i;
    struct hostent *host;
    struct sockaddr_in addr;                              
    if(argc!=2) {
        std::cout << "paramters not meet requires." << std::endl;
        exit(1);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_addr.s_addr=inet_addr(argv[1]);
    host=gethostbyaddr((char*)&addr.sin_addr,4, AF_INET);
    if(!host){
        std::cout <<"get host addr failed." << std::endl;
    }

    for (int i = 0; host->h_addr_list[i]; i++){
        std::cout << inet_ntoa(*(in_addr*)host->h_addr_list[i]) << std::endl;
    }
    
    return 0;
}
