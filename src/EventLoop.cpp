#include "EventLoop.h"

#include <event2/event.h>

EventLoop::EventLoop()
    : base_{event_base_new()}
{}

EventLoop::~EventLoop()
{
    event_base_free(base_);
}

event_base* EventLoop::get()
{
    return base_;
}

void EventLoop::loop()
{
    event_base_dispatch(base_);
}

void EventLoop::stop()
{
    event_base_loopbreak(base_);
}
