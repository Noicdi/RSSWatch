#ifndef RSSWATCH_INCLUDE_CONFIG_
#define RSSWATCH_INCLUDE_CONFIG_

#include <spdlog/spdlog.h>

#include <string>

struct Config
{
    // log
    spdlog::level::level_enum log_level;
    bool log_console;
    std::string log_path;

    // http
    std::string addr;
    uint16_t port;
};

Config getConfig();

void setLogConfig(Config& config);

#endif  // RSSWATCH_INCLUDE_CONFIG_
