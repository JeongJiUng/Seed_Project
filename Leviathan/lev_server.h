#pragma once
namespace lev
{
class cServer : public cSocket, public cBind, public cListen
{
public:
	cServer();
	cServer(string _server_option_dir);
	virtual ~cServer();

private:
	int						m_fd;
	cJson					m_server_option;

public:
	virtual void			start();
	virtual void			shutdown();

	void					set_fd(int _fd);
	int						get_fd();
};

class cLeviathanServer
{
public:
	cLeviathanServer(cServer* _server);
	virtual ~cLeviathanServer();

private:
	cServer*				m_server;

public:
	void					run();
	void					shutdown();
};
}