//
// Created by Administrator on 2023/5/13.
//

#ifndef TCP_CLIENT_H
#define TCP_CLIENT_H

#include <netinet/in.h>

class TCPClient {
public:
    TCPClient(const char* server_ip, int server_port);
    ~TCPClient();
    void run();

private:
    int client_fd_;
    struct sockaddr_in serv_;
};

#endif  // TCP_CLIENT_H
