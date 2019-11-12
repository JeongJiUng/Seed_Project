#include "lev.h"

lev::cEpollCreate::cEpollCreate()
{
}

lev::cEpollCreate::~cEpollCreate()
{
}

int lev::cEpollCreate::epoll_create()
{
	int						fd = ::epoll_create(1024);

	if (fd < 0)
	{
		//TODO:: PRINT LOG
		return FAIL;
	}

	return fd;
}