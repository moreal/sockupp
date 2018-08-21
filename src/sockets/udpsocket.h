//
// Created by moreal on 18. 8. 20.
//

#ifndef SOCKUPP_UDPSOCKET_H
#define SOCKUPP_UDPSOCKET_H

#include "socket.h"

#include <memory>

namespace sockupp {
    class UdpSocket;

    using UdpSocketPtr = std::shared_ptr<UdpSocket>;

    class UdpSocket : public Socket {
    public:
        explicit UdpSocket(const std::string& ip, const uint16_t port) noexcept
                : Socket(ip, port), m_isConnected(false), m_sockfd(0) {}
        explicit UdpSocket(const std::string& addr) noexcept
                : Socket(addr), m_isConnected(false), m_sockfd(0) {}
        explicit UdpSocket(const sockaddr& addr) noexcept
                : Socket(addr), m_sockfd(0) {}
        explicit UdpSocket(const Socket& socket) noexcept
                : Socket(socket), m_isConnected(false), m_sockfd(0) {}
                
        int Bind(Socket& socket) noexcept;
        int Listen(int backlog = 32) noexcept;
        int SendTo(Socket& socket, const void* data, const size_t len) noexcept;
        int ReceiveFrom(Socket& socket, void* buffer, const size_t len) noexcept;

        bool m_isConnected;

    private:
        int m_sockfd;
    };
}


#endif //SOCKUPP_UDPSOCKET_H
