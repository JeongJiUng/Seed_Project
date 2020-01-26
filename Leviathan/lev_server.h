#pragma once
namespace lev
{
#pragma pack(push, 1)
class cServer : public cMultiThreadSync<cServer>, public cThread
{
public:
	cServer();
	virtual ~cServer();

protected:
	bool					m_working;
	cServerOption			m_option;

protected:
	static void*			create_thread_helper(void* arg);
	
	virtual void*			proc_listen();
	virtual void			proc_shutdown();

public:
	void					run();
	void					stop();

	cServerOption			get_server_option();
};
#pragma pack(pop)
}