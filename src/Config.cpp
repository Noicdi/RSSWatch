#include "Config.h"

#include <spdlog/sinks/daily_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

#include "ConfFile.h"

static const auto CONF_FILE_PATH = "../conf/RSSWatch.conf";
static const auto LOG_FILE_NAME = "RSSWatch.log";

Config getConfig()
{
    Config conf{};
    ConfFile conf_file{CONF_FILE_PATH};

    conf.log_level = spdlog::level::from_str(conf_file.getParameterString("log", "level", "info"));
    conf.log_console = conf_file.getParameterBool("log", "console", false);
    conf.log_path = conf_file.getParameterString("log", "path", "../log");

    conf.addr = conf_file.getParameterString("http", "addr", "127.0.0.1");
    conf.port = conf_file.getParameterInt("http", "port", 6969);

    return conf;
}

void setLogConfig(Config& config)
{
    if (config.log_path[config.log_path.length() - 1] != '/')
    {
        config.log_path += "/";
    }
    config.log_path += LOG_FILE_NAME;

    auto daily_sink = std::make_shared<spdlog::sinks::daily_file_sink_mt>(config.log_path, 0, 0);
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    std::shared_ptr<spdlog::logger> logger;
    if (config.log_console)
    {
        logger = std::make_shared<spdlog::logger>("RSSWatch", spdlog::sinks_init_list{daily_sink, console_sink});
    }
    else
    {
        logger = std::make_shared<spdlog::logger>("RSSWatch", spdlog::sinks_init_list{daily_sink});
    }

    spdlog::register_logger(logger);
    spdlog::set_default_logger(logger);
    spdlog::set_level(config.log_level);
    spdlog::flush_on(config.log_level);
}
