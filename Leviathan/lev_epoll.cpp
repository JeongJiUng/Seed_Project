#include "lev.h"

lev::cEpoll::cEpoll()
{
}

lev::cEpoll::~cEpoll()
{
}

void lev::cEpoll::set_epoll_fd(int _fd)
{
	m_epoll					= _fd;
}

int lev::cEpoll::get_epoll_fd()
{
	return m_epoll;
}