#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include <unistd.h>
#include <string.h>
/* 文件操作步骤：
 * 1. 打开文件函数：open("readme.txt", O_WRONLY | O_APPEND | O_CREAT)
 * 2. 向文件中写入内容：write(fd1,content,sizeof(content))
 * 3. 读取文件中的内容：read(fd2,content,sizeof(content))
*/
int main(int argc,char** argv){
	// 打开文件，并向文件中写入内容
	int fd1 = open("readme.txt", O_WRONLY | O_APPEND | O_CREAT);
	if (fd1 == -1){
		std::cout <<"open file closed." << std::endl;
		exit(1);
	}
	
	char content[30] = "hello world...";
	write(fd1,content,sizeof(content));
	close(fd1);

	int fd2 = open("readme.txt",O_RDONLY);
	memset(content,0,sizeof(content));
	read(fd2,content,sizeof(content));
	std::cout << "read message: " << content << std::endl;

	return 0;
}