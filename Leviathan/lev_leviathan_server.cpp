#include "lev.h"

lev::cLeviathanServer::cLeviathanServer(cServerAdaptor* _server)
{
	m_server				= _server;
}

lev::cLeviathanServer::~cLeviathanServer()
{
	shutdown();
}

void lev::cLeviathanServer::run()
{
	cout << "#### SERVER START ####" << endl;

	m_server->start();
	m_server->loop();
}

void lev::cLeviathanServer::shutdown()
{
	//TODO:: 서버종료전, 저장해야 할 데이터 저장후 종료.
	m_server->server_data_save();
	m_server->shutdown();

	if (m_server != NULL)
		delete m_server;

	cout << "#### SERVER SHUTDOWN ####" << endl;
}