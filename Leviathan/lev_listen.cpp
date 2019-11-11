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
		// TODO:: PRINT LOG
		return FAIL;
	}

	return SUCC;
}