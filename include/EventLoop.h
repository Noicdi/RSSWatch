#ifndef RSSWATCH_INCLUDE_EVENTLOOP_
#define RSSWATCH_INCLUDE_EVENTLOOP_

struct event_base;

class EventLoop
{
  public:
    EventLoop();

    ~EventLoop();

    EventLoop(const EventLoop&) = delete;
    EventLoop(EventLoop&&) = delete;
    EventLoop operator=(const EventLoop&) = delete;
    EventLoop operator=(EventLoop&&) = delete;

    event_base* get();

    void loop();

    void stop();

  private:
    event_base* base_;
};

#endif  // RSSWATCH_INCLUDE_EVENTLOOP_
