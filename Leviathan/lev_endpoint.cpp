#include "lev.h"

lev::cEndpoint::cEndpoint(const char* _address, uint16_t _port)
{

	memset(&m_ivp4_endpoint, 0, sizeof(m_ivp4_endpoint));
	m_ivp4_endpoint.sin_family	= AF_INET;
	m_ivp4_endpoint.sin_port	= htons(_port);
	//if (_address == "")
	//	m_ivp4_endpoint.sin_addr.s_addr	= htonl(INADDR_ANY);
	//else
		inet_pton(AF_INET, _address, &m_ivp4_endpoint.sin_addr);
}

lev::cEndpoint::~cEndpoint()
{
}
