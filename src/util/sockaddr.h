//
// Created by moreal on 18. 8. 9.
//

#ifndef SRC_UTIL_SOCKADDR_H
#define SRC_UTIL_SOCKADDR_H

#include <string>
#include <algorithm>

#include "sock.h"

namespace sockupp {
    enum class ProtocolFamily {
        IPV4 = 4,
        IPV6 = 6,
        UNSUPPORTED = -1,
    };

    class SockAddrUtil {
        friend class SockUtil;

        const static inline ProtocolFamily getProtocolFamily(
                const std::string& addr) noexcept {
            int count[]{ 0, 0 };
            constexpr int COLUMN = 0, DOT = 1;

            std::for_each(addr.begin(), addr.end(), [&count](const auto& c) {
                if (c == ':')
                    ++count[COLUMN];
                else if (c == '.')
                    ++count[DOT];
            });

            if (count[DOT] == 3 && count[COLUMN] <= 1)
                return ProtocolFamily::IPV4;

            else if (count[COLUMN] <= 8)
                return ProtocolFamily::IPV6;
            else
                return ProtocolFamily::UNSUPPORTED;
        }
    };
}


#endif //SRC_UTIL_SOCKADDR_H
