#pragma once
namespace lev
{
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
}