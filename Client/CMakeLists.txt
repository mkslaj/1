cmake_minimum_required(VERSION 2.8)
project(Client)

set(CMAKE_CXX_STANDARD 11)

add_executable(Client main.cpp Socket.cpp Socket.h)
