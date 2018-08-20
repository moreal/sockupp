//
// Created by moreal on 18. 8. 20.
//

#include "udpsocket.h"


namespace sockupp {

    int UdpSocket::Bind(Socket &socket) noexcept {
        return bind(m_sockfd, &socket.GetSockAddress(), socket.GetSize());
    }

    int UdpSocket::Listen(int backlog) noexcept {
        return listen(m_sockfd, backlog);
    }

    int UdpSocket::SendTo(Socket& socket, const void *data, const size_t len) noexcept {
        return sendto(m_sockfd, data, len, 0, &socket.GetSockAddress(), socket.GetSize());
    }

    int UdpSocket::ReceiveFrom(Socket& socket, void *buffer, const size_t len) noexcept {
        return recvfrom(m_sockfd, buffer, len, 0, &socket.GetSockAddress(), &socket.GetSize());
    }
}
