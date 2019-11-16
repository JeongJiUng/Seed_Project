#pragma once
namespace lev
{
class cClient
{
public:
	cClient();
	virtual ~cClient();

private:
	string					m_ip;
	int						m_fd;

public:
	void					set_client(int _fd, string _ip);
};
}