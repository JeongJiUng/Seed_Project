#include "lev.h"
#include "lev_server.h"

lev::cServer::cServer()
{
	m_option.load_server_option(SERVER_OPTION);
}

lev::cServer::~cServer()
{
	shutdown();
}

void lev::cServer::start()
{
	cLock					lock;

	int						socket_type;
	if ("TCP" == m_option.get_type())
		socket_type			= SOCK_STREAM;
	else if ("UDP" == m_option.get_type())
		socket_type			= SOCK_DGRAM;
	
	m_fd					= socket(socket_type);
	if (m_fd == FAIL)
		return;

	if (bind(m_fd, m_option.get_port()) == FAIL)
	{
		return;
	}

	if (listen(m_fd, m_option.get_backlog()) == FAIL)
	{
		return;
	}
}

void* lev::cServer::loop()
{
	return NULL;
}

void lev::cServer::shutdown()
{
	cCloseSocket::get_instance()->close(m_fd);
}

void lev::cServer::set_fd(int _fd)
{
	cLock					lock;
	m_fd					= _fd;
}

int lev::cServer::get_fd()
{
	cLock					lock;
	return m_fd;
}

cServerOption lev::cServer::get_server_option()
{
	return m_option;
}
