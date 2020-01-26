#pragma once
namespace lev
{
#pragma pack(push, 1)
class cThread
{
public:
	cThread();
	virtual ~cThread();

private:
	pthread_t				m_tID;

public:
	virtual void			run() = 0;
	
	pthread_t				get_thread_id();

protected:
	bool					create_thread(void *_function(void* arg), void* context);
};
#pragma pack(pop)
}