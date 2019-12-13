#include "lev.h"

lev::cLeviathanServer::cLeviathanServer(cServerAdaptor* _server) : m_server(_server)
{
}

lev::cLeviathanServer::~cLeviathanServer()
{
	shutdown();
}

void lev::cLeviathanServer::run()
{
	cout << "#### SERVER INIT ####" << endl;
	cLog::get_instance()->write("LEV_INFO", "#### SERVER INIT ####\n");

	cout << "SERVER PORT : " << m_server->get_server_option().get_port() << endl;
	cLog::get_instance()->write("LEV_INFO", "SERVER PORT : %d\n", m_server->get_server_option().get_port());
	cout << "SERVER NUMBER : " << m_server->get_server_option().get_number() << endl;
	cLog::get_instance()->write("LEV_INFO", "SERVER NUMBER : %d\n", m_server->get_server_option().get_number());
	cout << "SERVER_NAME : " << m_server->get_server_option().get_name() << endl;
	cLog::get_instance()->write("LEV_INFO", "SERVER NUMBER : %s\n", m_server->get_server_option().get_name().c_str());

	cout << "#### SERVER START ####" << endl;
	cLog::get_instance()->write("LEV_INFO", "#### SERVER START ####\n");

	m_server->run();
}

void lev::cLeviathanServer::shutdown()
{
	//TODO:: 서버종료전, 저장해야 할 데이터 저장후 종료.
	if (m_server != NULL)
	{
		m_server->server_data_save();
		delete m_server;
	}

	cout << "#### SERVER SHUTDOWN ####" << endl;
	cLog::get_instance()->write("LEV_INFO", "#### SERVER SHUTDOWN ####\n");
}