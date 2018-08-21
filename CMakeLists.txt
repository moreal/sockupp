cmake_minimum_required(VERSION 3.12)
project(sockupp)

set(CMAKE_CXX_STANDARD 17)
set(LIBRARY_OUTPUT_PATH lib)

add_library(sockupp SHARED src/sockets/socket.h src/sockets/socket.cc src/sockets/tcpsocket.cc src/sockets/tcpsocket.h src/util/sock.cc src/util/sock.h src/util/sockaddr.h src/sockets/udpsocket.cc src/sockets/udpsocket.h tests/tcpsocket.cc)