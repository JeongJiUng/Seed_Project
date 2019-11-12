#pragma once
namespace lev
{
class cEpollServer : public cEpollCreate, public cEpollCTL, public cEpollWait
{
public:
	cEpollServer();
	virtual ~cEpollServer();

private:
	bool					m_shutdown;

private:
	bool					accept_clt();

public:
	void					start();
	void					loop();
	void					shutdown();
};
}