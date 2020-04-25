#include <iostream>
#include <arpa/inet.h>

int main(int argc,char** argv){
	// 将IP地址转换成一个32位的整型数值
	in_addr_t ip = inet_addr("192.168.0.16");
	std::cout << "IP value: " << ip << std::endl;

	// 经测试，本机系统为小端存储;而网络传输时会转换成大端存储。
	// 因此,打印出的newValue值与sValue值不同。
	int sValue = 12;
	std::cout << "sValue: " << sValue << std::endl;
	int newValue = htons(sValue);
	std::cout << "newValue: " << newValue << std::endl;

	// 网络字节序转换为本地字节序(即,还原成原来的数值)
	int original = ntohs(newValue);
	std::cout << "original: " << original << std::endl;
	
	return 0;
}