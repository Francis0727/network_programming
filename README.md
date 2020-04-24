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