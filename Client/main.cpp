#include <iostream>
#include <cstdlib>
#include "Socket.h"

int main(int argc, char* argv[])
{
    const char* server_ip ="192.168.88.130";  // 设置服务器 IP 地址
    int server_port = 9999;  // 设置服务器端口号

    TCPClient client(server_ip, server_port);
    client.run();
    return 0;
}

