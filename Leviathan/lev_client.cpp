#include "lev.h"

lev::cClient::cClient()
{
}

lev::cClient::~cClient()
{
}

void lev::cClient::set_client(int _fd, string _ip)
{
	m_fd					= _fd;
	m_ip					= _ip;
}
