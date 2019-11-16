#include "lev.h"

lev::cListen::cListen()
{
}

lev::cListen::~cListen()
{
}

bool lev::cListen::listen(int _fd, int _backlog)
{
	int						error = ::listen(_fd, _backlog);

	if (error < 0)
	{
		cLog::get_instance()->write("LEV_ERROR", "[LISTEN] FAIL, ERROR CODE [%d]\n", error);
		return FAIL;
	}

	return SUCC;
}