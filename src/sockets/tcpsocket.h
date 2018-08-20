//
// Created by moreal on 18. 8. 9.
//

#ifndef SOCKUPP_TCPSOCKET_H
#define SOCKUPP_TCPSOCKET_H

#include "socket.h"
#include "socket.cc"

#include <string>
#include <memory>

namespace sockupp {
    class TcpSocket : public Socket {
        using TcpSocketPtr = std::shared_ptr<TcpSocket>;

    public:

        explicit TcpSocket(const std::string& ip, const uint16_t port) noexcept
        : Socket(ip, port), m_isConnected(false), m_sockfd(0) {}
        explicit TcpSocket(const std::string& addr) noexcept
        : Socket(addr), m_isConnected(false), m_sockfd(0) {}
        explicit TcpSocket(const sockaddr& addr) noexcept
        : Socket(addr), m_sockfd(0) {}
        explicit TcpSocket(const Socket& socket) noexcept
        : Socket(socket), m_isConnected(false), m_sockfd(0) {}

        int Connect(Socket&) noexcept;
        int Bind(Socket&) noexcept;
        int Listen(int backlog = 32) noexcept;
        TcpSocketPtr Accept(const Socket &, bool) noexcept;
        int Send(const void*, const size_t) noexcept;
        int Receive(void*, const size_t) noexcept;

        bool m_isConnected;

    private:
        int m_sockfd;
    };

}


#endif //SOCKUPP_TCPSOCKET_H
