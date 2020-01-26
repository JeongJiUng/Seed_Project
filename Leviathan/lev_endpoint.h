#pragma once
namespace lev
{
#pragma pack(push, 1)
class cEndpoint
{
public:
	cEndpoint(const char* _address, uint16_t _port);
	virtual ~cEndpoint();

	struct sockaddr_in		m_ivp4_endpoint;
	uint16_t				m_port;
};
#pragma pack(pop)
}