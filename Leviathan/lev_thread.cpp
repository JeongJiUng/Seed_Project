#include "lev.h"
#include "lev_thread.h"

lev::cThread::cThread()
{
}

lev::cThread::~cThread()
{
}

pthread_t lev::cThread::get_thread_id()
{
	return m_tID;
}

bool lev::cThread::create_thread(void* _function(void* arg), void* context)
{
	int						error = 0;
	error					= pthread_create(&m_tID, NULL, _function, context);

	if (error < 0)
	{
		cLog::get_instance()->write("LEV_ERROR", "CREATE THREAD FAIL ERROR[%d]\n", error);
		return FAIL;
	}

	cLog::get_instance()->write("LEV_INFO", "CREATE THREAD. THREAD ID [%lu]\n", m_tID);
	cout << "CREATE THREAD. THREAD ID [" << m_tID << "]" << endl;
	return SUCC;
}
