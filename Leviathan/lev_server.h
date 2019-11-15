#pragma once
namespace lev
{
class cServer : public cSocket, public cBind, public cListen, public cAccept
{
public:
	cServer();
	virtual ~cServer();

protected:
	int						m_fd;
	cServerOption			m_option;

public:
	virtual void			start();
	virtual void			loop();
	virtual void			shutdown();

	void					set_fd(int _fd);
	int						get_fd();
};
}