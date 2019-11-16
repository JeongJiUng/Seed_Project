#pragma once
namespace lev
{
class cLeviathanServer
{
public:
	cLeviathanServer(cServerAdaptor* _server);
	virtual ~cLeviathanServer();

private:
	cServerAdaptor*			m_server;

public:
	void					run();
	void					shutdown();
};
}