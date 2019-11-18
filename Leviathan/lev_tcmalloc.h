#pragma once
namespace lev
{
/**
* tcmalloc ==> Thread-Caching Malloc.
* thread 별로 malloc 관리.
* 각각의 쓰레드에 thread-local cache를 배정한다.
* A Thread에서 tcmalloc을 통해 메모리를 할당하였으면, 반드시 A Thread에서 메모리를 회수해야한다.
**/
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