#include "lev.h"

lev::cEpollCTL::cEpollCTL()
{
}

lev::cEpollCTL::~cEpollCTL()
{
}

bool lev::cEpollCTL::epoll_ctl_add(int _fd)
{
	int						error;
	struct epoll_event		events;

	events.events			= EPOLLIN | EPOLLOUT | EPOLLET | EPOLLERR;
	events.data.fd			= _fd;

	error					= ::epoll_ctl(get_epoll_fd(), EPOLL_CTL_ADD, _fd, &events);

	if (error < 0)
	{
		//TODO:: PRINT LOG
		return FAIL;
	}

	return SUCC;
}

bool lev::cEpollCTL::epoll_ctl_del(int _fd)
{
	int						error;

	error					= ::epoll_ctl(get_epoll_fd(), EPOLL_CTL_ADD, _fd, NULL);

	if (error < 0)
	{
		//TODO:: PRINT LOG
		return FAIL;
	}

	return SUCC;
}