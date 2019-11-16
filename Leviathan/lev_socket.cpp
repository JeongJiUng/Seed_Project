#include "lev.h"

lev::cSocket::cSocket()
{
}

lev::cSocket::~cSocket()
{
}

int lev::cSocket::socket(int _type)
{
	int						fd = ::socket(PF_INET, _type, 0);
	
	if (fd < 0)
	{
		cLog::get_instance()->write("LEV_ERROR", "[SOCKET] FAIL, ERROR CODE [%d]\n", fd);
		return FAIL;
	}

	return fd;
}