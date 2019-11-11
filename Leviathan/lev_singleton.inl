namespace lev
{
	template <typename T>
	T* cSingleton<T>::m_pInstance	= nullptr;
	template <typename T>
	pthread_mutex_t cSingleton<T>::m_lock	= PTHREAD_MUTEX_INITIALIZER;

	template <typename T>
	T* cSingleton<T>::get_instance()
	{
		if (!m_pInstance)
		{
			pthread_mutex_lock(&m_lock);
			if (!m_pInstance)
			{
				static T		obj;
				m_pInstance		= &obj;
			}
			pthread_mutex_unlock(&m_lock);
		}

		return m_pInstance;
	}
}