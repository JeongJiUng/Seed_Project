#pragma once
namespace lev
{
class cEpollCreate : virtual public cEpoll
{
public:
	cEpollCreate();
	virtual ~cEpollCreate();

public:
	int						epoll_create();
};
}