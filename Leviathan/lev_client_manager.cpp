#include "lev.h"

lev::cClientManager::cClientManager()
{
}

lev::cClientManager::~cClientManager()
{
	m_clts.clear();
}

void lev::cClientManager::insert(SOCKET_INFO _clt)
{
	m_clts[_clt.fd];
}
