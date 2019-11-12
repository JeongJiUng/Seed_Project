#include "lev.h"
#include "lev_server.h"

lev::cServer::cServer()
{
	m_server_option.open_json_file(SERVER_OPTION);
}

lev::cServer::~cServer()
{
	shutdown();
}

void lev::cServer::start()
{
	int						socket_type;
	if ("TCP" == m_server_option.get_data("SERVER_TYPE").asString())
		socket_type			= SOCK_STREAM;
	else if ("UDP" == m_server_option.get_data("SERVER_TYPE").asString())
		socket_type			= SOCK_DGRAM;
	
	m_fd					= socket(socket_type);
	if (m_fd == FAIL)
		return;

	if (bind(m_fd, static_cast<uint16_t>(m_server_option.get_data("SERVER_PORT").asUInt())) == FAIL)
	{
		cCloseSocket::get_instance()->close(m_fd);
		return;
	}

	if (listen(m_fd, m_server_option.get_data("LISTEN_BACKLOG").asInt()) == FAIL)
	{
		cCloseSocket::get_instance()->close(m_fd);
		return;
	}
}

void lev::cServer::loop()
{

}

void lev::cServer::shutdown()
{
	cCloseSocket::get_instance()->close(m_fd);
}

void lev::cServer::set_fd(int _fd)
{
	m_fd					= _fd;
}

int lev::cServer::get_fd()
{
	return m_fd;
}