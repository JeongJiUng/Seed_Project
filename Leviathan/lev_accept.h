#pragma once
namespace lev
{
typedef struct accept_info
{
	int						fd;
	string					ip;
}ACCEPT_INFO;

class cAccept
{
public:
	cAccept();
	virtual ~cAccept();

public:
	ACCEPT_INFO				accept(int _server_fd);
};
}