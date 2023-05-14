#include <iostream>
#include <event2/event.h>
#include <arpa/inet.h>
#include <event2/listener.h>
#include <event2/bufferevent.h>
#include <event2/buffer.h>
#include "libeventServer.h"

void on_read_cb(struct bufferevent *bev,void *ctx )//bufferevent_setcb的readcb的回调函数
{
    struct evbuffer *input,*output = NULL;
    input= bufferevent_get_input(bev);
    output=bufferevent_get_output(bev);
    evbuffer_add_buffer(output,input);
}
void on_accept_cb(struct evconnlistener* listener,//evconnlistener* listener=evconnlistener_new_bind  cb的回调函数
                    evutil_socket_t fd,
                    struct sockaddr*addr,
                    int socklen,
                    void *ctx)
{
    struct event_base*base=NULL;//初始化base
    struct bufferevent *bev=NULL;//初始化bufferevent
    base= evconnlistener_get_base(listener);//获取base
    bev= bufferevent_socket_new(base,fd,0);//创建bufferevent
    bufferevent_enable(bev,EV_READ|EV_WRITE);//给bufferevent设置事件 读|写
    bufferevent_setcb(bev, on_read_cb,NULL,NULL,NULL);//设置回调函数
}


int main(int argc,char* argv[])
{
    LibeventServer lib;
    lib.run();
    return 0;
}
