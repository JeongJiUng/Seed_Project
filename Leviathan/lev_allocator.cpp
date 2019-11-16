#include "lev.h"

lev::cAllocator::cAllocator()
{
}

lev::cAllocator::~cAllocator()
{
}

cTCMalloc lev::cAllocator::get_memory()
{
	return m_tcmalloc;
}
