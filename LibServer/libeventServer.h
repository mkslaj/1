//
// Created by Administrator on 2023/5/15.
//

#ifndef LIBSERVER_LIBEVENTSERVER_H
#define LIBSERVER_LIBEVENTSERVER_H



#include <event2/event.h>
#include <arpa/inet.h>
#include <event2/listener.h>
#include <event2/bufferevent.h>
#include <event2/buffer.h>

class LibeventServer {
public:
    LibeventServer();
    ~LibeventServer();
    void run();

private:
    static void OnRead(struct bufferevent* bev, void* ctx);
    static void OnAccept(struct evconnlistener* listener, evutil_socket_t fd,
                         struct sockaddr* addr, int socklen, void* ctx);

    struct event_base* base_;
    struct evconnlistener* listener_;
};


#endif //LIBSERVER_LIBEVENTSERVER_H
