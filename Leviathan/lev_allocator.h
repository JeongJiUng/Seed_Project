#pragma once
namespace lev
{
class cAllocator : public cSingleton<cAllocator>, public cTCMalloc
{
public:
	cAllocator();
	virtual ~cAllocator();
};
}