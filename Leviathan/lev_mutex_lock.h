#pragma once
namespace lev
{
#pragma pack(push, 1)
class cMutexLock
{
public:
	cMutexLock();
	virtual ~cMutexLock();

private:
	pthread_mutex_t			m_lock;

public:
	void					lock();
	void					unlock();
};
#pragma pack(pop)
}