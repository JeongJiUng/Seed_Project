#pragma once
namespace lev
{
class cServerOption
{
public:
	cServerOption();
	virtual ~cServerOption();

private:
	cJson					m_option;

	string					m_server_name;
	string					m_server_type;

	uint16_t				m_server_port;
	int						m_server_number;
	int						m_server_connection_count;
	int						m_listen_backlog;

	int						m_epoll_max_event_count;

public:
	void					load_server_option(string _dir);

	string					get_name();
	string					get_type();

	uint16_t				get_port();
	int						get_number();
	int						get_connection_count();
	int						get_backlog();
	
	int						get_event_count();
};
}