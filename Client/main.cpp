#include <iostream>
#include <cstdlib>
#include "Socket.h"

int main(int argc, char* argv[])
{
    const char* server_ip ="192.168.88.130";  // ���÷����� IP ��ַ
    int server_port = 9999;  // ���÷������˿ں�

    TCPClient client(server_ip, server_port);
    client.run();
    return 0;
}

