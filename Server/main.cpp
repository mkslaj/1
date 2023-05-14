#include <iostream>
#include<signal.h>
#include "Server.h"
#include <unistd.h>
#include <stdlib.h>
#include <cstdio>
#include <fcntl.h>
#include <cstring>
#include <netinet/in.h>
#include "socket.h"
#include <sys/epoll.h>

void sighandlder(int sig)
{
    std::cout<<"received signal"
    <<sig<<std::endl;
}
void daemonize()
{


    int fd;
    pid_t pid;
    if (pid=fork()<0)
    {
        perror("fork son error");
    }
    else if (pid!=0)
    {
        exit(0);
    }
    //重定向
    setsid();
    //改变工作目录
    if (chdir("/") < 0)
    {
        perror("change dir !\n");
        exit(-1);
    }
    //重定向错误信息输出
    fd= open("/dev/null",O_RDWR);
    dup2(fd,STDIN_FILENO);
    dup2(fd,STDOUT_FILENO);
    dup2(fd,STDERR_FILENO);
}
int main(int argc,char* argv[])
{
    TCPServer server(9999);
        if (!server.start()) {
            std::cerr << "Failed to start server" << std::endl;
            return 1;
        }
        server.run();
        return 0;
    }
//    char buf[1024];
//    int socket_fd= socket(AF_INET,SOCK_STREAM,0);
//    int opt = 1;
//    setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(int));
//    struct sockaddr_in serv,clientaddr;
//    int addr_len =sizeof(struct sockaddr);
//    std::memset(&serv, 0, sizeof(serv));
//    serv.sin_family = AF_INET;
//    serv.sin_port = htons(8888);
//    serv.sin_addr.s_addr = htonl(INADDR_ANY);//htons 函数用于将 16 位的主机字节序转换为网络字节序
//    //INADDR_ANY: 表示使用本机任意有效的可用IP
//    // inet_pton(AF_INET, "127.0.0.1", &serv.sin_addr.s_addr);
//    //addrlen: addr变量的占用的内存大小
//
//
//    int ret;
//    ret = bind(socket_fd, (struct sockaddr *) &serv, sizeof(struct sockaddr));
//
//    if (ret == -1)
//    {
//        std::cerr << "Failed to bind socket" << std::endl;
//        return false;
//    }
//    int backlog=5;
//    int tet;
//    tet = listen(socket_fd,backlog);
//    if(tet==-1)
//    {
//        std::cerr<<"Failed to listen socket"<<std::endl;
//        exit(-1);
//    }
//    for(;;)//死循环接受连接
//    {
//        int accept_fd;
//        accept_fd = accept(socket_fd, (struct sockaddr *) &clientaddr, reinterpret_cast<socklen_t *>(&addr_len));
//        for(;;)//死循环收数据
//        {
//            int ret =recv(accept_fd,(void*)buf,sizeof(buf),0);
//            if(ret==0)
//            {
//                break;
//            }
//            std::cout<<buf<<std::endl;
//            send(accept_fd,(void*)buf,sizeof(buf),0);
//        }
//        close(accept_fd);
//    }
//    close(socket_fd);
//    return 0;

//    if (daemon(0,0)==-1)
//    {
//        std::cout<<"error\n"<<std::endl;
//        exit(-1);
//    }
//    while(1)
//    {
//        sleep(1);
//    }
//    //放到后台执行
//    daemonize();
//    //创建信号
//    struct sigaction act,oact;
//    act.sa_handler= sighandlder;
//    sigfillset(&act.sa_mask);
//    act.sa_flags=0;
//    sigaction(SIGINT,&act,&oact);
//    pause();
//    return 0;

