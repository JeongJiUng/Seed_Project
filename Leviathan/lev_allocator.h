#pragma once
namespace lev
{
#pragma pack(push, 1)
class cAllocator : public cSingleton<cAllocator>, public cTCMalloc
{
public:
	cAllocator();
	virtual ~cAllocator();
};
#pragma pack(pop)
}