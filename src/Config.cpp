#include "Config.h"

#include "ConfFile.h"

static const auto CONF_FILE_PATH = "../conf/RSSWatch.conf";

Config getConfig()
{
    Config conf{};
    ConfFile conf_file{CONF_FILE_PATH};

    conf.level = spdlog::level::from_str(conf_file.getParameterString("log", "level", "info"));

    conf.addr = conf_file.getParameterString("http", "addr", "127.0.0.1");
    conf.port = conf_file.getParameterInt("http", "port", 6969);

    return conf;
}
