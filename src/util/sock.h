//
// Created by moreal on 18. 8. 9.
//

#ifndef SOCKUPP_SOCKETUTIL_H
#define SOCKUPP_SOCKETUTIL_H

#include <string>
#include <sys/types.h>
#include <netinet/in.h>

namespace sockupp {
    class SockUtil {
        friend class Socket;

    private:
        static sockaddr getSockAddr(const std::string &);
    };
}

#endif //SOCKUPP_SOCKETUTIL_H
