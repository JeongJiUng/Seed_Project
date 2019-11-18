#include "lev.h"

lev::cMutexLock::cMutexLock()
{
	pthread_mutex_init(&m_lock, NULL);
}

lev::cMutexLock::~cMutexLock()
{
	pthread_mutex_destroy(&m_lock);
}

void lev::cMutexLock::lock()
{
	pthread_mutex_lock(&m_lock);
}

void lev::cMutexLock::unlock()
{
	pthread_mutex_unlock(&m_lock);
}
