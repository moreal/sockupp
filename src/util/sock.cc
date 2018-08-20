//
// Created by moreal on 18. 8. 9.
//

#include <iostream>
#include <string>
#include <cstring>

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>

#include "sock.h"
#include "sockaddr.h"

namespace sockupp {
    sockaddr SockUtil::getSockAddr(const std::string &addr) {
        const auto protocolFamily = SockAddrUtil::getProtocolFamily(addr);

        struct sockaddr sockAddr;

        std::memset(&sockAddr, 0, sizeof sockAddr);

        if (protocolFamily != ProtocolFamily::IPV4 && protocolFamily != ProtocolFamily::IPV6)
            return sockAddr;

        std::string ip, port;
        addrinfo hint, *result;

        std::memset(&hint, 0, sizeof hint);

        if (protocolFamily == ProtocolFamily::IPV4) {
            auto pos = addr.find(':');

            if (pos == std::string::npos) {
                ip = addr;
                port = "0";
            } else {
                ip = addr.substr(0, pos);
                port = addr.substr(pos + 1);
            }

            hint.ai_family = AF_INET;

        } else if (protocolFamily == ProtocolFamily::IPV6) {
            auto pos = addr.find("]:");

            if (pos == std::string::npos) {
                ip = addr;
                port = "0";
            } else {
                ip = addr.substr(0, pos);
                port = addr.substr(pos + 2);
            }

            hint.ai_family = AF_INET6;

        }

        int error = getaddrinfo(ip.c_str(), port.c_str(), &hint, &result);

        if (error != 0 && result != nullptr) {
            freeaddrinfo(result);
            return sockAddr;
        }

        while (!result->ai_addr && result->ai_next) {
            result = result->ai_next;
        }

        if (!result->ai_addr) {
            freeaddrinfo(result);
            return sockAddr;
        }

        sockAddr = *result->ai_addr;
        freeaddrinfo(result);

        return sockAddr;
    }
    sockaddr SockUtil::getSockAddr(const std::string &ip, const uint16_t port) {
        auto protocolFamily = SockAddrUtil::getProtocolFamily(ip);

        switch (protocolFamily) {
            case ProtocolFamily::IPV4:
                sockaddr_in sockaddrIn;
                sockaddrIn.sin_family = AF_INET;
                sockaddrIn.sin_port = port;
                inet_pton(AF_INET, ip.c_str(), &sockaddrIn.sin_addr);
                return *((sockaddr*) &sockaddrIn);

            case ProtocolFamily::IPV6:
                sockaddr_in6 sockaddrIn6;
                sockaddrIn6.sin6_family = AF_INET6;
                sockaddrIn6.sin6_port = port;
                inet_pton(AF_INET6, ip.c_str(), &sockaddrIn6.sin6_addr);
                return *((sockaddr*) &sockaddrIn6);

            default:
                sockaddr sockAddr;
                std::memset(&sockAddr, 0, sizeof sockAddr);
                return sockAddr;
        }
    }
}