#include "lev.h"
// https://github.com/gperftools/gperftools

lev::cTCMalloc::cTCMalloc()
{
}

lev::cTCMalloc::~cTCMalloc()
{
}

void* lev::cTCMalloc::alloc(const size_t _size)
{
	return tc_new(_size);
}

void* lev::cTCMalloc::alloc_array(const size_t _size)
{
	return tc_newarray(_size);
}

void lev::cTCMalloc::dealloc(void* _p)
{
	tc_delete(_p);
	_p						= NULL;
}

void lev::cTCMalloc::dealloc_array(void* _p)
{
	tc_deletearray(_p);
	_p						= NULL;
}
