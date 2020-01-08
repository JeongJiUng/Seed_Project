#pragma once
namespace lev
{
#pragma pack(push, 1)
class cEpoll
{
public:
	cEpoll();
	cEpoll(int _max_event_count);
	virtual ~cEpoll();

private:
	int						m_epoll;
	int						m_max_event_count;

public:
	void					close();
	bool					epoll_ctl_add(int _fd, void* _user_ptr, int _event_flags);
	int						epoll_wait(epoll_event* _output, int _timeout);
	
	void					set_epoll(int _fd);
	
	int						get_epoll();
	int						get_max_event_count();
};
#pragma pack(pop)
}