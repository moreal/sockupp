//
// Created by moreal on 18. 8. 9.
//

#include "tcpsocket.h"

#include <sys/socket.h>
#include <sys/types.h>
#include <cstring>
#include <arpa/inet.h>
#include <netdb.h>

namespace sockupp {
    using TcpSocketPtr = std::shared_ptr<TcpSocket>;

    int TcpSocket::Connect(Socket &socket) noexcept {
        return connect(m_sockfd, &socket.GetSockAddress(), socket.GetSize());
    }

    int TcpSocket::Bind(Socket &socket) noexcept {
        return bind(m_sockfd, &socket.GetSockAddress(), socket.GetSize());
    }

    int TcpSocket::Listen(int backlog) noexcept {
        return listen(m_sockfd, backlog);
    }

    int TcpSocket::Send(const void *data, const size_t len) noexcept {
        return send(m_sockfd, data, len, 0);
    }

    int TcpSocket::Receive(void *buffer, const size_t len) noexcept {
        return recv(m_sockfd, buffer, len, 0);
    }

    TcpSocketPtr TcpSocket::Accept(
            const Socket &dest,
            bool isNonBlocking) noexcept {

        Socket socket;

        accept4(m_sockfd, &socket.GetSockAddress(), &socket.GetSize(), isNonBlocking ? SOCK_NONBLOCK : 0);
        return std::make_shared<TcpSocket>(socket);
    }
}
