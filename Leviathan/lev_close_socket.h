#pragma once
namespace lev
{
class cCloseSocket : public cSingleton<cCloseSocket>, public cMultiThreadSync<cCloseSocket>
{
public:
	void					close(int _fd);
};
}