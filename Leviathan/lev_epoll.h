#pragma once
namespace lev
{
class cEpoll : public cServer
{
public:
	cEpoll();
	virtual ~cEpoll();

private:
	int						m_epoll;

public:
	void					set_epoll_fd(int _fd);
	int						get_epoll_fd();
};
}