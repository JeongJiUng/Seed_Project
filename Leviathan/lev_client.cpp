#include "lev.h"

lev::cClient::cClient() : m_message(NULL), m_ip(""), m_fd(0)
{
}

lev::cClient::cClient(int _fd, string _ip) : m_message(NULL), m_ip(_ip), m_fd(_fd)
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

void lev::cClient::set_message(char* _message)
{
	m_message				= move(_message);
}
