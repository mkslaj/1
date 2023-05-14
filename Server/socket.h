//
// Created by Administrator on 2023/5/12.
//

#ifndef SERVER_SOCKET_H
#define SERVER_SOCKET_H


#include <sys/epoll.h>
const int max=20;
const int timeout =500;
class TCPServer {
public:
    TCPServer(int port);
    bool start();
    void run();
    ~TCPServer();

private:
    struct epoll_event ev,events[max];
    int epfd;
    int m_port;
    int m_server_fd;
    int accept_fd;
    char buffer[1024];
    int ret;
};


#endif //SERVER_SOCKET_H
