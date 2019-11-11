#pragma once
namespace lev
{
class cCloseSocket : public cSingleton<cCloseSocket>
{
public:
	void					close(int _fd);
};
}