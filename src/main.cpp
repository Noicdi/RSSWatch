#include "Config.h"
#include "HttpServer.h"

int main()
{
    auto conf = getConfig();

    spdlog::set_level(conf.level);

    HttpServer server(conf.addr, conf.port);
    server.run();

    return 0;
}
