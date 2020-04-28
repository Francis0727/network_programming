#include <iostream>
#include <sys/types.h>        
#include <sys/socket.h>

int main(int argc,char** argv){
    int snd_buf = 1024 * 10;
    int serv_sock = socket(AF_INET,SOCK_STREAM,0);
    if (serv_sock == -1){
        std::cout << "create socket failed." << std::endl;
        exit(1);
    }
    
    // 获取默认设置下，发送缓冲区的大小
    int optval = -2;
    socklen_t optlen = sizeof(optval);
    // 获取成功返回0，失败返回-1
    int state = getsockopt(serv_sock,SOL_SOCKET,SO_SNDBUF,(void*)&optval,&optlen);
    if (state == -1){
        std::cout << "get socket option failed." << std::endl;
        exit(1);
    }
    std::cout <<"sendbuf size: " << optval << std::endl;

    // 重新设置缓冲区的大小并读取
    state = setsockopt(serv_sock,SOL_SOCKET,SO_SNDBUF,&snd_buf,optlen);
    if (state == -1){
        std::cout << "set socket failed." << std::endl;
        exit(1);
    }
    state = getsockopt(serv_sock,SOL_SOCKET,SO_SNDBUF,(void*)&optval,&optlen);
    if (state == -1){
        std::cout << "get socket option failed." << std::endl;
        exit(1);
    }
    std::cout <<"sendbuf size: " << optval << std::endl;

    return 0;
}