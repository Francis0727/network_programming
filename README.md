# 基于网络的服务端和客户端通信<br>
## 实现功能: <br>
>客户端连接到服务器后，服务器向客户端发送字符串“hello world”.<br>
>客户端接收到数据后，打印接收到的信息。<br>
## 使用到的函数<br>
> socket(PF_INET, SOCK_STREAM, 0)<br>
> bind(serv_sd, (struct sockaddr*)&serv_adr, sizeof(serv_adr))<br>
> listen(serv_sd, 5)<br>
> accept(serv_sd, (struct sockaddr*)&clnt_adr, &clnt_adr_sz)<br>
> close(clnt_sd)<br>
> connect(serv_sock,(sockaddr*)&serv_addr,sizeof(serv_addr))<br>
# 02 文件的读取操作<br>
## 实现功能<br>
>首先打开文件->并向文件中写入内容->关闭文件；接着重新打开文件-><br>
>读取文件中的内容->打印出读取到的内容。<br>
## 使用到的函数归纳<br>
> open("readme.txt", O_WRONLY | O_APPEND | O_CREAT)<br>
> write(fd1,content,sizeof(content))<br>
> read(fd2,content,sizeof(content));<br>
# 03 TCP通信的无边界问题<br>
## 实现功能<br>
> 服务器端一次性发送完整的数据包，客户端分为多次进行接收。通过这个实验，
> 来验证TCP通信无边界问题(即,read函数调用次数不必与write函数调用次数相对应)
# 04 大小端问题<br>
## 实现功能<br>
> char指针指向int类型变量(值为1),通过判断int类型的起始地址来判断大小端。
> 注: 低位存放在大端，则是大端存储；低位存放在小端，则是小端存储(大端、小端
>     说的是地址的首尾部分)
# 05 大小端问题<br>
## 实现功能<br>
> 1. 将字符串IP地址(例如,"192.168.139.88")转换成一个32位的整型数值。
> 2. 网络字节序与本机字节序的相互转换
# 06 实现迭代服务器、客户端<br>
## 实现功能<br>
> 1. 服务器可接收多个客户端的连接，但某时刻只能处理某个客户端(非并发)
> 2. 客户端连接到服务端后，服务器向客户端发送数据；客户端接收到数据后，
>    向服务器回传数据
# 07 实现迭代服务器、客户端<br>
## 实现功能<br>
> 实现自定义的通信协议。即发送数据为: 数据的长度信息 + 真实有效的数据。
> 对数据解读: 获取信息的长度数据，根据长度数据获取服务器端真实发送过来的数据
# 08 实现迭代服务器、客户端<br>
## 实现功能<br>
> 客户端连接到服务器后，服务器将一份文件发送到客户端。客户端接收到完整的文件后，
> 向服务器发送thanks you(难点: 采用半关闭表明已发送完成)