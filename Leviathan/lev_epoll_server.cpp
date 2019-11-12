#include "lev.h"

lev::cEpollServer::cEpollServer()
{
}

lev::cEpollServer::~cEpollServer()
{
}

bool lev::cEpollServer::accept_clt()
{
	ACCEPT_INFO				info;
	cClient					client;

	info					= accept(get_fd());
	if (info.fd == FAIL)
		return FAIL;

	// set non-blocking socket
	int						flags = fcntl(info.fd, F_GETFL);
	flags					|= O_NONBLOCK;
	if (fcntl(info.fd, F_SETFL, flags) < 0)
	{
		//TODO:: PRINT LOG
		return FAIL;
	}

	if (epoll_ctl_add(info.fd) == FAIL)
	{
		//TODO:: PRINT LOG
		cCloseSocket::get_instance()->close(info.fd);
		return FAIL;
	}

	//TODO:: 클라이언트 매니저에 접속한 클라이언트 정보 추가.
	client.set_client(info.fd, info.ip);

	return SUCC;
}

void lev::cEpollServer::start()
{
	cServer::start();

	set_epoll_fd(epoll_create());
	if (get_epoll_fd() == FAIL)
	{
		cCloseSocket::get_instance()->close(get_fd());
		return;
	}

	if (epoll_ctl_add(get_fd()) == FAIL)
	{
		cCloseSocket::get_instance()->close(get_fd());
		cCloseSocket::get_instance()->close(get_epoll_fd());
		return;
	}

	m_shutdown				= false;
}

void lev::cEpollServer::loop()
{
	int						event_count;
	int						max_events = m_server_option.get_data("EPOLL_MAX_EVENT_COUNT").asInt();
	struct epoll_event		epoll_events[max_events];

	while (!m_shutdown)
	{
		event_count			= epoll_wait(epoll_events, max_events);

		if (event_count < 0)
		{
			//TODO:: PRINT LOG
			return;
		}

		for (int i = 0; i < event_count; i++)
		{
			if (epoll_events[i].data.fd == get_fd())
			{
				//TODO:: Connect Client
				if (accept_clt() == FAIL)
					continue;
			}
			else
			{
				//TODO:: PUSH RECV QUEUE
			}
		}
	}
}

void lev::cEpollServer::shutdown()
{
	m_shutdown				= true;

	cCloseSocket::get_instance()->close(get_epoll_fd());
	cCloseSocket::get_instance()->close(get_fd());
}
