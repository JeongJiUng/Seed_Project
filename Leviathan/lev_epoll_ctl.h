#pragma once
namespace lev
{
class cEpollCTL : virtual public cEpoll
{
public:
	cEpollCTL();
	virtual ~cEpollCTL();

public:
	bool					epoll_ctl_add(int _fd);
	bool					epoll_ctl_del(int _fd);
};
}