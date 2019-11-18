#pragma once
namespace lev
{
template <class T>
class cMultiThreadSync
{
	friend class cMutexLock;

public:
	class cLock
	{
	public:
		cLock();
		~cLock();
	};

private:
	static cMutexLock			m_mutex;
};

template <class T>
inline cMultiThreadSync<T>::cLock::cLock()
{
	T::m_mutex.lock();
}

template <class T>
inline cMultiThreadSync<T>::cLock::~cLock()
{
	T::m_mutex.unlock();
}

template <class T>
cMutexLock cMultiThreadSync<T>::m_mutex;
}