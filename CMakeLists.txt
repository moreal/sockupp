cmake_minimum_required(VERSION 3.12)
project(sockupp)

set(CMAKE_CXX_STANDARD 17)

add_library(sockupp SHARED src/sockets/socket.cc src/sockets/socket.h src/sockets/tcpsocket.cc src/sockets/tcpsocket.h src/util/sock.cc src/util/sock.h src/util/sockaddr.cc src/util/sockaddr.h)