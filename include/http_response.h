#ifndef INCLUDED_HTTP_RESPONSE
#define INCLUDED_HTTP_RESPONSE

#include <string>
#include <unordered_map>

namespace http {
    class HttpResponse  {
        public:
            void addHeader(std::string name, std::string value);
            std::string output() const;
    
        private:
            std::unordered_map<std::string, std::string> headers;
            std::string body;
        };
}

#endif
