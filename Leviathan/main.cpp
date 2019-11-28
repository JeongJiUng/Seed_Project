#include "lev.h"

//valgrind --leak-check=full --error-limit=no ./Leviathan.out
//https://m.blog.naver.com/PostView.nhn?blogId=cksdn788&logNo=220380070991&proxyReferer=https%3A%2F%2Fwww.google.com%2F

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

	string					input;
	while (true)
	{
		cin >> input;

		if (input == "exit")
		{
			break;
		}
	}

	lev_server.shutdown();

	return 0;
}