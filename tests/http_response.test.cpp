#include <gtest/gtest.h>
#include <http_response.h>

TEST(HttpResponseClass, SimpleResponse) {
    http::HttpResponse response;
    EXPECT_EQ(response.output(), "test");
}