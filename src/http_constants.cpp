#include <http_constants.h>

namespace http {
    const std::string httpMethodString(HttpMethod method) {
        if (httpMethodStringHash.contains(method)) {
            return std::string(httpMethodStringHash.at(method));
        }
        return "Unknown";
    }
}