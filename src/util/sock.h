//
// Created by moreal on 18. 8. 9.
//

#ifndef SOCKUPP_SOCKETUTIL_H
#define SOCKUPP_SOCKETUTIL_H

#include <string>
#include <sys/types.h>
#include <netinet/in.h>

#include "../sockets/tcpsocket.h"

namespace sockupp {
    class SockUtil {
        friend class Socket;

    private:
        static sockaddr getSockAddr(const std::string &);
        static sockaddr getSockAddr(const std::string &, const uint16_t);
    };
}

#endif //SOCKUPP_SOCKETUTIL_H
