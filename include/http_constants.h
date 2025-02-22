#ifndef INCLUDED_HTTP_CONSTANTS
#define INCLUDED_HTTP_CONSTANTS

#include <string>
#include <unordered_map>

namespace http {
    enum class HttpMethod {
        GET,
        HEAD,
        POST,
        PUT,
        DELETE,
        CONNECT,
        OPTIONS,
        TRACE,
        PATCH
    };

    constexpr std::pair<HttpMethod, const char*> data[] = {
        {HttpMethod::GET, "GET"},
        {HttpMethod::HEAD, "HEAD"},
        {HttpMethod::POST, "POST"},
        {HttpMethod::PUT, "PUT"},
        {HttpMethod::DELETE, "DELETE"},
        {HttpMethod::CONNECT, "CONNECT"},
        {HttpMethod::OPTIONS, "OPTIONS"},
        {HttpMethod::TRACE, "TRACE"},
        {HttpMethod::PATCH, "PATCH"}
    };

    inline const std::unordered_map<HttpMethod, const char*> httpMethodStringHash(
        std::begin(data), std::end(data)
    );

    const std::string httpMethodString(HttpMethod method);

    enum class HttpStatusCode {
        Continue = 100,
        SwitchingProtocols = 101,
        EarlyHints = 103,
        Ok = 200,
        Created = 201,
        Accepted = 202,
        NonAuthoritativeInformation = 203,
        NoContent = 204,
        ResetContent = 205,
        PartialContent = 206,
        MultipleChoices = 300,
        MovedPermanently = 301,
        Found = 302,
        NotModified = 304,
        BadRequest = 400,
        Unauthorized = 401,
        Forbidden = 403,
        NotFound = 404,
        MethodNotAllowed = 405,
        RequestTimeout = 408,
        ImATeapot = 418,
        InternalServerError = 500,
        NotImplemented = 501,
        BadGateway = 502,
        ServiceUnvailable = 503,
        GatewayTimeout = 504,
        HttpVersionNotSupported = 505
    };
}

#endif
