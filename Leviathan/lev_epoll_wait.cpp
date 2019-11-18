#include "lev.h"

lev::cEpollWait::cEpollWait()
{
}

lev::cEpollWait::~cEpollWait()
{
}

int lev::cEpollWait::epoll_wait(epoll_event* _event, int _max_events)
{
	cLock					lock;

	int						event_count = 0;

	do
	{
		event_count			= ::epoll_wait(get_epoll_fd(), _event, _max_events, -1);
	} while (event_count < 0 && errno == EINTR);

	return event_count;
}