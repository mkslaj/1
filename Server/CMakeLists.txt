cmake_minimum_required(VERSION 2.8)
project(Server)

set(CMAKE_CXX_STANDARD 11)

add_executable(Server main.cpp Server.cpp Server.h socket.cpp socket.h)
