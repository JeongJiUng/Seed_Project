#include "lev.h"

lev::cEpoll::cEpoll()
{
	m_epoll					= -1;
}

lev::cEpoll::cEpoll(int _max_event_count)
{
	m_epoll					= epoll_create(_max_event_count);
	m_max_event_count		= _max_event_count;
}

lev::cEpoll::~cEpoll()
{
	close();
}

void lev::cEpoll::close()
{
	::close(m_epoll);
}

bool lev::cEpoll::epoll_ctl_add(int _fd, void* _user_ptr, int _event_flags)
{
	int						error;
	struct epoll_event		events;
	
	events.events			= _event_flags;
	events.data.ptr			= _user_ptr;
	error					= epoll_ctl(m_epoll, EPOLL_CTL_ADD, _fd, &events);

	if (error != 0)
	{
		cLog::get_instance()->write("LEV_ERROR", "[%d] [EPOLL CTL ADD] FAIL, ERROR CODE [%d]\n", _fd, error);
		return FAIL;
	}

	return SUCC;
}

int lev::cEpoll::epoll_wait(epoll_event* _output, int _timeout)
{
	int						event_count = 0;

	do
	{
		event_count			= ::epoll_wait(m_epoll, _output, m_max_event_count, _timeout);
	} while(event_count < 0 && errno == EINTR);

	return event_count;
}

void lev::cEpoll::set_epoll(int _fd)
{
	m_epoll					= _fd;
}

int lev::cEpoll::get_epoll()
{
	return m_epoll;
}

int lev::cEpoll::get_max_event_count()
{
	return m_max_event_count;
}
