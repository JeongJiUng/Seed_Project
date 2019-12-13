#pragma once
namespace lev
{
class cEpoll
{
public:
	cEpoll();
	virtual ~cEpoll();

private:
	int						m_epoll;

public:
};
}