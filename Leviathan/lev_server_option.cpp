#include "lev.h"

lev::cServerOption::cServerOption()
{
}

lev::cServerOption::~cServerOption()
{
}

void lev::cServerOption::load_server_option(string _dir)
{
	m_option.open_json_file(_dir);

	m_server_name			= m_option.get_data("SERVER_NAME").asString();
	m_server_number			= m_option.get_data("SERVER_NUMBER").asInt();
	m_server_type			= m_option.get_data("SERVER_TYPE").asString();
	m_server_port			= static_cast<uint16_t>(m_option.get_data("SERVER_PORT").asUInt());

	m_listen_backlog		= m_option.get_data("LISTEN_BACKLOG").asInt();

	m_epoll_max_event_count	= m_option.get_data("EPOLL_MAX_EVENT_COUNT").asInt();

	/** LOG DIR OPTION LOAD. **/
	cLog::get_instance()->load_log_option(m_option);
}

string lev::cServerOption::get_name()
{
	return m_server_name;
}

string lev::cServerOption::get_type()
{
	return m_server_type;
}

uint16_t lev::cServerOption::get_port()
{
	return m_server_port;
}

int lev::cServerOption::get_number()
{
	return m_server_number;
}

int lev::cServerOption::get_connection_count()
{
	return m_server_connection_count;
}

int lev::cServerOption::get_backlog()
{
	return m_listen_backlog;
}

int lev::cServerOption::get_event_count()
{
	return m_epoll_max_event_count;
}
