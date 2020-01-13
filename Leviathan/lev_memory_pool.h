#pragma once
namespace lev
{

/**
* 현재 tcmalloc 사용해서 따로 연산자 오버로딩 할 필요 없음.
* tcmalloc ==> Thread-Caching Malloc.
* thread 별로 malloc 관리.
* 각각의 쓰레드에 thread-local cache를 배정한다.
* A Thread에서 tcmalloc을 통해 메모리를 할당하였으면, 반드시 A Thread에서 메모리를 회수해야한다.
**/

//class cMemoryPool
//{
//public:
//	void*					operator new(size_t _size);
//	void*					operator new[](size_t _size);
//
//	void					operator delete(void* _p);
//	void					operator delete[](void* _p);
//};
}