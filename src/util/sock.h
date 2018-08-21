//
// Created by moreal on 18. 8. 9.
//

#ifndef SRC_UTIL_SOCK_H
#define SRC_UTIL_SOCK_H

#include <string>
#include <sys/types.h>
#include <netinet/in.h>

namespace sockupp {
    class SockUtil {
        friend class Socket;

    private:
        static sockaddr getSockAddr(const std::string &);
        static sockaddr getSockAddr(const std::string &, uint16_t);
    };
}

#endif  // SRC_UTIL_SOCK_H