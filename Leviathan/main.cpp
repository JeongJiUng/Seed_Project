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
};



int main()
{
	cout << "hello World!!" <<endl;

	
	srand(time(NULL));
	long start = get_tick();
	for (int i = 0; i < 1000000; i++)
	{
		int* test			= new int[rand()];
		delete[]			test;
	}
	cout << get_tick() - start << endl;

	//cTestServer				server;
	//server.run();
	//
	//string					input;
	//while (true)
	//{
	//	cin >> input;

	//	if (input == "exit")
	//	{
	//		server.stop();
	//		break;
	//	}
	//}
	
	return 0;
}