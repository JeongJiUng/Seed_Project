#include "lev.h"

lev::cEpoll::cEpoll()
{
}

lev::cEpoll::~cEpoll()
{
}

void lev::cEpoll::set_epoll_fd(int _fd)
{
	cLock					lock;

	m_epoll					= _fd;
}

int lev::cEpoll::get_epoll_fd()
{
	cLock					lock;

	return m_epoll;
}