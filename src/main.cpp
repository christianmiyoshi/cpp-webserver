#include <http_tcpserver.h>

int main()
{
    using namespace http;

    TcpServer server {"127.0.0.1", 8080};
    server.startListen();

    return 0;
}