#pragma once

namespace lev
{
	template <typename T>
	class cSingleton
	{
	public:
		cSingleton() {}
		~cSingleton()
		{
			/*if (m_pInstance != nullptr)
			delete this;*/
		}

	private:
		static T*				m_pInstance;
		static pthread_mutex_t	m_lock;

	public:
		static T*				get_instance();
	};
}

// include inline file
#include "lev_singleton.inl"