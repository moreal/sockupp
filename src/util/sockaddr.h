//
// Created by moreal on 18. 8. 9.
//

#ifndef SOCKUPP_SOCKADDR_H
#define SOCKUPP_SOCKADDR_H

#include <string>
#inlcude "sock.h"

namespace sockupp {
    enum class ProtocolFamily {
        IPV4 = 4,
        IPV6 = 6,
        UNSUPPORTED = -1,
    };

    class SockAddrUtil {
        friend class SockUtil;
        const static inline ProtocolFamily getProtocolFamily(const std::string&) noexcept;
    };
}


#endif //SOCKUPP_SOCKADDR_H
