//
// Created by Administrator on 2023/5/13.
//

#include "Socket.h"
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstdlib>
#include <cstdio>
#include <cerrno>

TCPClient::TCPClient(const char* server_ip, int server_port)
{
    // 创建客户端socket
    client_fd_ = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd_ < 0) {
        std::cerr << "Failed to create socket" << std::endl;
        exit(-1);
    }

    // 设置服务器地址
    memset(&serv_, 0, sizeof(serv_));
    serv_.sin_family = AF_INET;
    serv_.sin_port = htons(server_port);
    serv_.sin_addr.s_addr = inet_addr(server_ip);

    // 连接服务器
    int conn_fd = connect(client_fd_, (struct sockaddr*)&serv_, sizeof(serv_));
    if (conn_fd < 0)
    {
        std::cerr << "Failed to connect" << std::endl;
        exit(-1);
    }
}

TCPClient::~TCPClient()
{
    close(client_fd_);
}

void TCPClient::run()
{
    char buf[1024];
    while (true) {
        memset(buf, 0, sizeof(buf));
        std::cout << "Please input message: ";
        std::cin.getline(buf, sizeof(buf)); // 读取用户输入
        int ret = send(client_fd_, buf, strlen(buf), 0);
        if (ret <= 0) {
            std::cerr << "Failed to send" << std::endl;
        }

        if (strcmp(buf, "quit") == 0) {
            break;
        }

        // 接收数据
        int total_recv = 0;
        while (total_recv < sizeof(buf) - 1) {
            ret = recv(client_fd_, buf + total_recv, sizeof(buf) - total_recv - 1, 0);
            if (ret == -1) {
                if (errno == EAGAIN || errno == EWOULDBLOCK) {
                    break;
                } else {
                    std::cerr << "Failed to receive" << std::endl;
                    break;
                }
            } else if (ret == 0) {
                // 连接断开
                std::cerr << "Connection closed by server" << std::endl;
                break;
            } else {
                total_recv += ret;
            }
        }
        buf[total_recv] = '\0'; // 在缓冲区后面加上字符串结束符
        std::cout << "Received message: " << buf << std::endl;
    }
}

