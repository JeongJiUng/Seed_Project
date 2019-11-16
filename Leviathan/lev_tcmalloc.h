#pragma once
namespace lev
{
class cTCMalloc : public cMemoryPool
{
public:
	cTCMalloc();
	virtual ~cTCMalloc();

public:
	void*					alloc(const size_t _size);
	void*					alloc_array(const size_t _size);
	void					dealloc(void* _p);
	void					dealloc_array(void* _p);
};
}