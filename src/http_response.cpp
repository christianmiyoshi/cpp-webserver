#include <http_response.h>
#include <sstream>

namespace http {
    void HttpResponse::addHeader(std::string name, std::string value) {
        this->headers[name] = value;
    }

    std::string HttpResponse::output() const {
        std::ostringstream ss;

        ss << "HTTP/1.1 200 OK\n";

        for (auto& header : headers) {  // It's better to use reference here to avoid copying
            ss << header.first << ": " << header.second << "\n";
        }        
        ss << "Content-Type: text/html\nContent-Length: " << body.size() << "\n\n"
           << body;
        return ss.str();
    }
}