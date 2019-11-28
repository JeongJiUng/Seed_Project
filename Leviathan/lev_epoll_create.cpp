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
		cLog::get_instance()->write("LEV_ERROR", "[EPOLL CREATE] FAIL, ERROR CODE [%d]\n", fd);
		return FAIL;
	}

	return fd;
}