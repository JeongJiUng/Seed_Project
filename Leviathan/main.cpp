#include "lev.h"

int main()
{
	cout << "hello World!!" <<endl;

	cLeviathanServer		lev_server(new cServer("/home/leviathan/projects/Leviathan/server_options/server_option.json"));
	lev_server.run();

	return 0;
}