//
// Created by Administrator on 2023/5/12.
//

#include "socket.h"
#include <cstring>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <cerrno>




TCPServer::TCPServer(int port) : m_port(port), m_server_fd(-1) {}

bool TCPServer::start() {
    // 创建 Socket
    m_server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (m_server_fd == -1) {
        std::cerr << "Failed to create socket" << std::endl;
        return false;
    }
    // 设置 Socket 选项，允许地址重用
    int opt = 1;
    if (setsockopt(m_server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(int)) == -1) {
        std::cerr << "Failed to set socket option" << std::endl;
        return false;
    }
    // 绑定 IP 地址和端口号
    struct sockaddr_in server_addr;
    std::memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(m_port);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(m_server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) ==-1)
    {
        std::cerr << "Failed to bind socket" << std::endl;
        return false;
    }
    // 监听连接请求
    int backlog = 5;
    if (listen(m_server_fd, backlog) == -1) {
        std::cerr << "Failed to listen on socket" << std::endl;
        return false;
    }
    std::cout << "Server started on port " << m_port << std::endl;
    int fd=m_server_fd;
    return true;
}

void TCPServer::run()
{
    struct sockaddr_in client_addr;
    socklen_t addr_len = sizeof(client_addr);
    ev.events=EPOLLIN;//监听后设置
    ev.data.fd=m_server_fd;
    epfd=epoll_create(256);//创建epfd
    epoll_ctl(epfd,EPOLL_CTL_ADD,m_server_fd,&ev);
    for (;;)
    {
        int epoll_number=epoll_wait(epfd,events,max,timeout);//等待监听的所有fd相应事件的产生
        for (int i=0;i<epoll_number;++i)
        {
            if (events[i].data.fd==m_server_fd)
            {
                // 接受连接请求
                accept_fd = accept(m_server_fd, (struct sockaddr*)&client_addr, &addr_len);
                if (accept_fd == -1)
                {
                    std::cerr << "Failed to accept connection" << std::endl;
                    continue;
                }
                int flags=fcntl(accept_fd,F_GETFL,0);//在创建连接后设置非阻塞
                fcntl(accept_fd,F_SETFL,flags|O_NONBLOCK);//设置accept非阻塞
                ev.events=EPOLLIN|EPOLLET;//接收设置边缘模式
                ev.data.fd=accept_fd;
                epoll_ctl(epfd,EPOLL_CTL_ADD,accept_fd,&ev);
            } else if (events[i].events&EPOLLIN)
            {
                std::cout << "Accepted new connection" << std::endl;
                do
                {
                    memset(buffer,0,sizeof(buffer));
                    ret = recv(events[i].data.fd, buffer, sizeof(buffer), 0);
                    if (ret == 0) {
                        // 连接断开
                        close(events[i].data.fd);
                    } else if (ret<0&&errno==EINTR) {
                        // 系统中断，重试接收
                        continue;
                    } else if (ret<0) {
                        // 接收数据出错
                        std::cerr << "Failed to receive data" << std::endl;
                        break;
                    } else {
                        // 接收数据成功
                        int total_recv = ret;
                        while (total_recv < sizeof(buffer)) {
                            ret = recv(events[i].data.fd, buffer + total_recv, sizeof(buffer) - total_recv, 0);
                            if (ret == -1) {
                                if (errno == EAGAIN || errno == EWOULDBLOCK) {
                                    break;
                                } else {
                                    std::cerr << "Failed to receive data" << std::endl;
                                    break;
                                }
                            } else if (ret == 0) {
                                // 连接断开
                                close(events[i].data.fd);
                                break;
                            } else {
                                total_recv += ret;
                            }
                        }
                        buffer[total_recv] = '\0'; // 在缓冲区后面加上字符串结束符
                        std::cout << "Received data: " << buffer << std::endl;

                        // 发送数据
                        int total_sent = 0;
                        while (total_sent < total_recv) {
                            ret = send(events[i].data.fd, buffer + total_sent, total_recv - total_sent, 0);
                            if (ret == -1) {
                                if (errno == EAGAIN || errno == EWOULDBLOCK) {
                                    break;
                                } else {
                                    std::cerr << "Failed to send data" << std::endl;
                                    break;
                                }
                            } else {
                                total_sent += ret;
                            }
                        }

                        // 关闭连接
                       // close(events[i].data.fd);
                        std::cout << "Connection closed" << std::endl;
                    }
                }
                while (ret > 0 && errno != EAGAIN && errno != EWOULDBLOCK); // 循环接收数据，直到缓冲区为空或出现错误
            }
        }
    }
}

TCPServer::~TCPServer() {
    if (m_server_fd != -1) {
        close(m_server_fd);
    }
}