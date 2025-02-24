#include <http_response.h>
#include <sstream>

namespace http {
    void HttpResponse::addHeader(std::string name, std::string value) {
        this->headers[name] = value;
    }

    int HttpResponse::statusInt() const {
        return static_cast<int>(status);
    }

    std::string HttpResponse::output() const {
        std::ostringstream ss;
        ss << "HTTP/1.1 " << std::to_string(statusInt()) << " OK\n";

        for (auto& header : headers) {
            ss << header.first << ": " << header.second << "\n";
        }        
        ss << "Content-Type: text/html\nContent-Length: " << body.size();

        if (body.size() > 0) {
            ss << "\n\n" << body;
        }
        return ss.str();
    }
}