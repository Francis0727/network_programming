#include <iostream>
#include <sys/types.h>        
#include <sys/socket.h>

int main(int argc,char** argv){
    int serv_sock = socket(AF_INET,SOCK_STREAM,0);
    if (serv_sock == -1){
        std::cout << "create socket failed." << std::endl;
        exit(1);
    }
    
    int optval = -2;
	// 注: optlen的值须初始化，不然无法获取到sokcet的type值
    socklen_t optlen = sizeof(optval);
    // 获取成功返回0，失败返回-1
    int state = getsockopt(serv_sock,SOL_SOCKET,SO_TYPE,(void*)&optval,&optlen);
    if (state == -1){
        std::cout << "get socket option failed." << std::endl;
        exit(1);
    }
    std::cout << "SOCK_STREAM: " << SOCK_STREAM << std::endl;
    std::cout <<"socket type: " << optval << std::endl;

    return 0;
}