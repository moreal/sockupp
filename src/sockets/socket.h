#ifndef SRC_SOCKETS_SOCKET_H
#define SRC_SOCKETS_SOCKET_H

#include "tcpsocket.h"

#include <string>

#include <sys/types.h>
#include <netinet/in.h>

namespace sockupp {
    class Socket {

    public:
        Socket(const std::string&, const uint16_t) noexcept;
        explicit Socket(const std::string&) noexcept;
        explicit Socket(const sockaddr&) noexcept;
        Socket() noexcept;

        inline socklen_t & GetSize() noexcept;
        inline sockaddr& GetSockAddress() noexcept;

    private:
        sockaddr m_sockaddr;
        socklen_t m_socklen;
    };
}

#endif