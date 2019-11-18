#pragma once
namespace lev
{
/**
* tcmalloc ==> Thread-Caching Malloc.
* thread ���� malloc ����.
* ������ �����忡 thread-local cache�� �����Ѵ�.
* A Thread���� tcmalloc�� ���� �޸𸮸� �Ҵ��Ͽ�����, �ݵ�� A Thread���� �޸𸮸� ȸ���ؾ��Ѵ�.
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