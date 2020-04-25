#include <iostream>

int main(int argc,char** argv){
	// 大端存储: 0x00000001
	// 小端存储: 0x01000000
	// 识别方法: 低位放在大端，则是大端存储；地位放在小端，则是小端存储
	int m_ival = 0x01;
	char* pt = reinterpret_cast<char*>(&m_ival);
	if (*pt == 0x01){
		std::cout << "小端存储." << std::endl;
	}else{
		std::cout << "大端存储." << std::endl;
	}
	
	return 0;
}