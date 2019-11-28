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

protected:
	static void*			create_thread_helper(void* arg);

public:
	void					start();
	void*					loop();
	void					shutdown();

	void					run();
};
}