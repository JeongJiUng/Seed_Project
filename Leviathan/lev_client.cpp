#include "lev.h"

lev::cClient::cClient() : cSocket(-1, ""), m_heart_beat(true), m_message(NULL)
{
}

lev::cClient::cClient(int _fd, string _ip) : cSocket(_fd, _ip), m_heart_beat(true), m_message(NULL)
{
}

lev::cClient::~cClient()
{
}

void lev::cClient::set_client(bool _heart_beat, int _fd, string _ip)
{
	m_heart_beat			= _heart_beat;
	m_fd					= _fd;
	m_ip					= _ip;
}

void lev::cClient::set_message(char* _message)
{
	m_message				= move(_message);
}
