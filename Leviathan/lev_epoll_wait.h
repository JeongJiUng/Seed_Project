#pragma once
namespace lev
{
class cEpollWait : virtual public cEpoll
{
public:
	cEpollWait();
	virtual ~cEpollWait();

public:
	int						epoll_wait(struct epoll_event* _event, int _max_events);
};
}