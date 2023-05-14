//
// Created by Administrator on 2023/5/15.
//
#include <cstring>
#include <iostream>
#include "libeventServer.h"
LibeventServer::LibeventServer() {
    base_ = event_base_new();
}

LibeventServer::~LibeventServer() {
    if (listener_) {
        evconnlistener_free(listener_);
    }
    if (base_) {
        event_base_free(base_);
    }
}

void LibeventServer::run() {
    struct sockaddr_in serveraddr;
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(9999);
    serveraddr.sin_addr.s_addr = INADDR_ANY; //设置任意IP可用

    listener_ = evconnlistener_new_bind(base_, OnAccept, this,
                                        LEV_OPT_REUSEABLE | LEV_OPT_CLOSE_ON_FREE,
                                        -1, (struct sockaddr*)&serveraddr, sizeof(serveraddr));
    if (!listener_) {
        std::cerr << "Failed to create listener\n";
        return;
    }

    event_base_dispatch(base_);
}

void LibeventServer::OnRead(struct bufferevent* bev, void* ctx) {
    struct evbuffer* input = bufferevent_get_input(bev);
    struct evbuffer* output = bufferevent_get_output(bev);
    evbuffer_add_buffer(output, input);
}

void LibeventServer::OnAccept(struct evconnlistener* listener, evutil_socket_t fd,
                              struct sockaddr* addr, int socklen, void* ctx) {
    LibeventServer* server = static_cast<LibeventServer*>(ctx);
    struct event_base* base = evconnlistener_get_base(listener);
    struct bufferevent* bev = bufferevent_socket_new(base, fd, BEV_OPT_CLOSE_ON_FREE);
    bufferevent_setcb(bev, OnRead, NULL, NULL, NULL);
    bufferevent_enable(bev, EV_READ | EV_WRITE);
}