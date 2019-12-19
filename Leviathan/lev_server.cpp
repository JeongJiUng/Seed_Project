#include "lev.h"

lev::cServer::cServer()
{
	m_option.load_server_option(SERVER_OPTION);
	m_working				= true;
}

lev::cServer::~cServer()
{
}

void* lev::cServer::create_thread_helper(void* arg)
{
	return ((cServer*)arg)->proc_listen();
}

void* lev::cServer::proc_listen()
{
	cout << "#### SERVER INIT ####" << endl;
	cLog::get_instance()->write("LEV_INFO", "#### SERVER INIT ####\n");

	int						event_count = m_option.get_event_count();
	cEpoll					epoll(event_count);

	SocketType				type;
	if ("TCP" == m_option.get_type())
		type				= SocketType::TCP;
	else if ("UDP" == m_option.get_type())
		type				= SocketType::UDP;

	// TCP 리슨 소켓 생성.
	cSocket					listen_socket(type);
	listen_socket.bind(cEndpoint("0.0.0.0", m_option.get_port()));
	listen_socket.set_nonblocking();
	listen_socket.listen(m_option.get_backlog());

	// TCP 리슨 소켓 epoll에 추가.
	epoll.epoll_ctl_add(listen_socket.get_fd(), nullptr, EPOLLIN | EPOLLET | EPOLLERR);

	cout << "SERVER PORT : " << m_option.get_port() << endl;
	cLog::get_instance()->write("LEV_INFO", "SERVER PORT : %d\n", m_option.get_port());
	cout << "SERVER NUMBER : " << m_option.get_number() << endl;
	cLog::get_instance()->write("LEV_INFO", "SERVER NUMBER : %d\n", m_option.get_number());
	cout << "SERVER_NAME : " << m_option.get_name() << endl;
	cLog::get_instance()->write("LEV_INFO", "SERVER NUMBER : %s\n", m_option.get_name().c_str());

	cout << "#### SERVER START ####" << endl;
	cLog::get_instance()->write("LEV_INFO", "#### SERVER START ####\n");

	while (m_working)
	{
		// I/O 이벤트 대기
		int					event_count;
		epoll_event			events[event_count];
		event_count			= epoll.epoll_wait(events, -1);

		// 받은 이벤트 처리
		for (int i = 0; i < event_count; i++)
		{
			auto&			event = events[i];
			
			if (event.data.fd == listen_socket.get_fd())
			{
				// TODO:: 클라이언트 커넥트
				SOCKET_INFO	clt;
				while (true)
				{
					if (listen_socket.accept(clt) == FAIL)
					{
						break;
					}
				}
			}
		}
	}

	proc_shutdown();

	return nullptr;
}

void lev::cServer::proc_shutdown()
{
}

void lev::cServer::run()
{
	cLog::get_instance()->write("LEV_INFO", "CREATE SERVER LISTEN THREAD\n");
	cout << "CREATE SERVER LISTEN THREAD" << endl;
	if (create_thread(create_thread_helper, (cServer*)this) == FAIL)
	{
		cLog::get_instance()->write("LEV_ERROR", "FAIL CREATE SERVER LISTEN THREAD\n");
		cout << "FAIL CREATE SERVER LISTEN THREAD" << endl;
	}
}

void lev::cServer::stop()
{
	m_working				= false;
}

cServerOption lev::cServer::get_server_option()
{
	return m_option;
}