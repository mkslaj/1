//
// Created by Administrator on 2023/5/12.
//

#include <iostream>
#include <unistd.h>
#include "Server.h"

Server::Server()
{
    std::cout<<"construct"<<std::endl;
}
Server::~Server()
{
    std::cout<<"destruct"<<std::endl;
}

void Server::run()
{
    while (1)
    {
        std::cout<<"run"<<std::endl;
        ::usleep(10000);
    }
}
