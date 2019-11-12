#include "lev.h"

lev::cAccept::cAccept()
{
}

lev::cAccept::~cAccept()
{
}

lev::ACCEPT_INFO lev::cAccept::accept(int _server_fd)
{
	ACCEPT_INFO				info;

	struct sockaddr_in		addr;
	int						addr_len = sizeof(addr);
	
	info.fd					= ::accept(_server_fd, (struct sockaddr*)&addr, (socklen_t*)&addr_len);
	if (info.fd < 0)
	{
		//TODO:: PRINT LOG
		info.fd				= FAIL;
		return info;
	}
	else
	{
		//TODO:: PRINT ACCPET LOG
		info.ip				= inet_ntoa(addr.sin_addr);
	}

	return info;
}
