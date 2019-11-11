#pragma once
namespace lev
{
class cListen
{
public:
	cListen();
	virtual ~cListen();

public:
	bool					listen(int _fd, int _backlog);
};
}