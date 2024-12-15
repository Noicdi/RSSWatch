#ifndef RSSWATCH_INCLUDE_HTTPSERVER_
#define RSSWATCH_INCLUDE_HTTPSERVER_

#include <memory>
#include <string>

struct evhttp;
struct evhttp_request;
class EventLoop;

class HttpServer
{
  public:
    HttpServer(const std::string& addr, const uint16_t port);

    ~HttpServer();

    HttpServer(const HttpServer&) = delete;
    HttpServer(HttpServer&&) = delete;
    HttpServer& operator=(const HttpServer&) = delete;
    HttpServer& operator=(HttpServer&&) = delete;

    void run();

  private:
    static void httpRequestHandle(struct evhttp_request* req, void* arg);

    std::string addr_;
    uint16_t port_;

    std::unique_ptr<EventLoop> loop_;
    evhttp* http_server_;
};

#endif  // RSSWATCH_INCLUDE_HTTPSERVER_
