#include <iostream>
#include <sys/uio.h>
#include <string.h>

int main(int argc,char** argv){
    struct iovec vec[2];
    char buf1[100] = {0};
    char buf2[100] = {0};
    memset(buf1,0,sizeof(buf1));
    memset(buf2,0,sizeof(buf2));

    vec[0].iov_base = buf1;
    vec[0].iov_len = 5;
    vec[1].iov_base = buf2;
    vec[1].iov_len = 5;

    // 从标准输入读取信息
    readv(0,vec,2);
    std::cout << "buf1: " << buf1 << std::endl;
    std::cout << "buf2: " << buf2 << std::endl;
    writev(1,vec,2);
    
    return 0;
}