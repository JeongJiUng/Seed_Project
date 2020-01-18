namespace lev
{
	template<class T>
	inline cCircularQueue<T>::cCircularQueue() : m_queue_head (0), m_queue_tail(0)
	{
	}

	template<class T>
	inline cCircularQueue<T>::~cCircularQueue()
	{
	}

	template<class T>
	inline bool cCircularQueue<T>::push(T _data)
	{
		cLock				lock;

		int					temp_tail = (m_queue_tail + 1) % MAX_QUEUE_LENGTH;

		if (temp_tail == m_queue_head)
			return FAIL;

		memcpy(&m_queue[temp_tail], &_data, sizeof(T));

		m_queue_tail		= temp_tail;

		return SUCC;
	}

	template<class T>
	inline bool cCircularQueue<T>::pop(T& _data)
	{
		cLock				lock;

		if (m_queue_head == m_queue_tail)
			return FAIL;

		int					temp_head = (m_queue_head + 1) % MAX_QUEUE_LENGTH;

		memcpy(&data, &m_queue[temp_head], sizeof(T));

		m_queue_head		= temp_head;

		return SUCC;
	}

	template<class T>
	inline bool cCircularQueue<T>::isEmpty()
	{
		cLock				lock;

		if (m_queue_head == m_queue_tail)
			return true;
		
		return false;
	}
}
