#include "lev.h"

class cTestServer : public cServerAdaptor
{
public:
	cTestServer()
	{
	}

	virtual ~cTestServer()
	{
	}

public:
	void server_data_save()
	{

	}
};

int main()
{
	cout << "hello World!!" <<endl;

	cLeviathanServer		lev_server(new cTestServer);
	lev_server.run();

	return 0;
}