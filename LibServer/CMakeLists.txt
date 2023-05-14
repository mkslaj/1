cmake_minimum_required(VERSION 2.8)
project(LibServer)

set(CMAKE_CXX_STANDARD 14)
find_library(EVENT_LIBRARY event)
add_executable(LibServer main.cpp libeventServer.cpp libeventServer.h)

target_link_libraries(LibServer  PRIVATE ${EVENT_LIBRARY})

