//
// Created by moreal on 18. 8. 9.
//

#include <algorithm>
#include "sockaddr.h"

namespace sockupp {
    const inline ProtocolFamily SockAddrUtil::getProtocolFamily(
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
}
