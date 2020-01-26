#include "lev.h"

lev::cClientManager::cClientManager()
{
}

lev::cClientManager::~cClientManager()
{
	m_clts.clear();
}

void lev::cClientManager::begin(int _max_clt_count, int _listen_socket)
{
	cLock					lock;
	for (int i = 0; i < _max_clt_count; i++)
	{
		cClient*			clt = new cClient();
		m_clts.push_back(clt);
	}

	if (_listen_socket < 1)
		return;

	for (int i = 0; i < (int)m_clts.size(); i++)
	{
		if (m_clts[i]->get_fd() < 1)
			continue;

		if (m_clts[i]->accept(_listen_socket) == FAIL)
		{
			break;
		}
	}
}

void lev::cClientManager::insert(SOCKET_INFO _clt)
{
	cLock					lock;
	m_clts[_clt.fd];
}