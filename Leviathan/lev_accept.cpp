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
		cLog::get_instance()->write("LEV_ERROR", "[ACCEPT] FAIL, ERROR CODE [%d]\n", info.fd);
		info.fd				= FAIL;
		return info;
	}
	else
	{
		info.ip				= inet_ntoa(addr.sin_addr);
	}

	return info;
}
