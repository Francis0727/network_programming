#include <iostream>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc,char** argv) {
    if (argc != 2){
        std::cout <<"paramters not meet requires." << std::endl;
        exit(1);
    }
    
    hostent* host = gethostbyname(argv[1]);
    if (host == NULL){
        std::cout << "get host by name falled." << std::endl;
        return -1;
    }
    
    for (int i = 0; host->h_addr_list[i]; i++){
        std::cout << inet_ntoa(*(in_addr*)host->h_addr_list[i]) 
  << std::endl;
    }
    
    return 0;
}
