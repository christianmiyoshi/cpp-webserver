#ifndef INCLUDED_HTTP_RESPONSE
#define INCLUDED_HTTP_RESPONSE

#include <string>
#include <http_constants.h>
#include <unordered_map>

namespace http {
    class HttpResponse  {
        public:
            HttpResponse(HttpStatusCode status) : status(status) {};
            void addHeader(std::string name, std::string value);
            std::string output() const;
            int statusInt() const;
    
        private:
            std::unordered_map<std::string, std::string> headers;
            std::string body;
            HttpStatusCode status;
        };
}

#endif
