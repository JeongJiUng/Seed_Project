#pragma once
namespace lev
{
template <class T>
class cCircularQueue : public cLock<cCircularQueue>
{
public:
	cCircularQueue();
	virtual ~cCircularQueue();

private:
	T						m_queue[MAX_QUEUE_LENGTH];
	int						m_queue_head;
	int						m_queue_tail;

public:
	bool					push(T _data);
	bool					pop(T& _data);
	bool					isEmpty();
};
}

#include "lev_circular_queue.inl"