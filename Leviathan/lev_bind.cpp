#include "lev.h"

lev::cBind::cBind()
{
}

lev::cBind::~cBind()
{
}

bool lev::cBind::bind(int _fd, uint16_t _port)
{
	struct sockaddr_in		addr;
	
	memset(&addr, 0, sizeof(addr));
	addr.sin_family			= AF_INET;
	addr.sin_port			= htons(_port);
	addr.sin_addr.s_addr	= htonl(INADDR_ANY);

	int						error = ::bind(_fd, (struct sockaddr*)&addr, sizeof(addr));
	
	if (error < 0)
	{
		//TODO:: PRINT LOG
		return FAIL;
	}

	return SUCC;
}