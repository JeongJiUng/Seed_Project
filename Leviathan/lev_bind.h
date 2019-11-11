#pragma once
namespace lev
{
class cBind
{
public:
	cBind();
	virtual ~cBind();

public:
	bool					bind(int _fd, uint16_t _port);
};
}