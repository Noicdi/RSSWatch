#include "Config.h"
#include "HttpServer.h"

int main()
{
    auto config = getConfig();

    setLogConfig(config);

    HttpServer server(config.addr, config.port);
    server.run();

    return 0;
}
