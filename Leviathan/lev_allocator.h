#pragma once
namespace lev
{
class cAllocator : public cSingleton<cAllocator>
{
public:
	cAllocator();
	virtual ~cAllocator();

private:
	cTCMalloc				m_tcmalloc;

public:
	cTCMalloc				get_memory();
};
}