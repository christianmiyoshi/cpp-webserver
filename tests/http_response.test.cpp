#include <gtest/gtest.h>
#include <http_response.h>
#include <http_constants.h>

TEST(HttpResponseClass, SimpleResponse) {
    http::HttpResponse response(http::HttpStatusCode::Ok);
    EXPECT_EQ(response.output(), "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: 0");
}