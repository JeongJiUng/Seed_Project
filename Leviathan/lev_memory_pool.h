#pragma once
namespace lev
{

/**
* ���� tcmalloc ����ؼ� ���� ������ �����ε� �� �ʿ� ����.
* tcmalloc ==> Thread-Caching Malloc.
* thread ���� malloc ����.
* ������ �����忡 thread-local cache�� �����Ѵ�.
* A Thread���� tcmalloc�� ���� �޸𸮸� �Ҵ��Ͽ�����, �ݵ�� A Thread���� �޸𸮸� ȸ���ؾ��Ѵ�.
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