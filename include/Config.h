#ifndef RSSWATCH_INCLUDE_CONFIG_
#define RSSWATCH_INCLUDE_CONFIG_

#include <spdlog/spdlog.h>

#include <string>

struct Config
{
    // log
    spdlog::level::level_enum level;

    // http
    std::string addr;
    uint16_t port;
};

Config getConfig();

#endif  // RSSWATCH_INCLUDE_CONFIG_
