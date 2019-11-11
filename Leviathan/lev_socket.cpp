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
		//TODO:: PRINT LOG
		return FAIL;
	}

	return fd;
}