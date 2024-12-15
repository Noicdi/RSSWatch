#include "HttpServer.h"

#include <event2/buffer.h>
#include <event2/http.h>
#include <event2/keyvalq_struct.h>
#include <spdlog/spdlog.h>

#include <map>

#include "EventLoop.h"

static std::string getHttpRequestMethod(enum evhttp_cmd_type cmd)
{
    switch (cmd)
    {
        case EVHTTP_REQ_GET:
            return "GET";
        case EVHTTP_REQ_POST:
            return "POST";
        case EVHTTP_REQ_HEAD:
            return "HEAD";
        case EVHTTP_REQ_PUT:
            return "PUT";
        case EVHTTP_REQ_DELETE:
            return "DELETE";
        default:
            return "UNKNOWN";
    }
}

HttpServer::HttpServer(const std::string& addr, const uint16_t port)
    : addr_{addr},
      port_{port},
      loop_{std::make_unique<EventLoop>()},
      http_server_{evhttp_new(loop_->get())}
{
    evhttp_bind_socket(http_server_, addr_.c_str(), port_);
    spdlog::debug("Http Server listening {}:{}", addr_, port_);

    evhttp_set_gencb(http_server_, httpRequestHandle, nullptr);
}

HttpServer::~HttpServer()
{
    evhttp_free(http_server_);

    loop_->stop();
}

void HttpServer::run()
{
    loop_->loop();
}

void HttpServer::httpRequestHandle(struct evhttp_request* req, void* arg)
{
    auto request_method = evhttp_request_get_command(req);
    auto request_decode =
        std::unique_ptr<evhttp_uri, void (*)(evhttp_uri*)>(evhttp_uri_parse(evhttp_request_get_uri(req)),
                                                           evhttp_uri_free);
    auto http_request_path = evhttp_uri_get_path(request_decode.get());

    spdlog::info("Http request: {} {}", getHttpRequestMethod(request_method), http_request_path);

    auto request_headers = evhttp_request_get_input_headers(req);
    std::map<std::string, std::string> header_map;
    for (auto header = request_headers->tqh_first; header; header = header->next.tqe_next)
    {
        header_map[header->key] = header->value;
    }

    auto response_body = std::unique_ptr<evbuffer, void (*)(evbuffer*)>(evbuffer_new(), evbuffer_free);
    evbuffer_add_printf(response_body.get(), "RSSWatch is working!");
    evhttp_send_reply(req, HTTP_OK, NULL, response_body.get());
}
