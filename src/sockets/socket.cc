#include <netdb.h>
#include <iostream>
#include <cstring>

#include "socket.h"
#include "../util/sock.h"

namespace sockupp {
    Socket::Socket(const std::string &ip, const uint16_t port) noexcept {
        m_sockaddr = SockUtil::getSockAddr(ip, port);
        m_socklen = sizeof m_sockaddr;
    }

    Socket::Socket(const std::string &addr) noexcept {
        m_sockaddr = SockUtil::getSockAddr(addr);
        m_socklen = sizeof m_sockaddr;
    }

    Socket::Socket(const sockaddr& sockAddr) noexcept {
        m_sockaddr = sockAddr;
        m_socklen = sizeof m_sockaddr;
    }

    Socket::Socket() noexcept {
        std::memset(&GetSockAddress(), 0, GetSize());
    }

    inline socklen_t & Socket::GetSize() noexcept {
        return m_socklen;
    }

    inline sockaddr& Socket::GetSockAddress() noexcept {
        return m_sockaddr;
    }

}

// TODO: Setting Test
// TODO: Util