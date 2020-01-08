#pragma once
namespace lev
{
#pragma pack(push, 1)
class cMemoryPool
{
public:
	cMemoryPool();
	virtual ~cMemoryPool();

public:
	virtual void*			alloc(const size_t _size) = 0;
	virtual void*			alloc_array(const size_t _size) = 0;
	virtual void			dealloc(void* _p) = 0;
	virtual void			dealloc_array(void* _p) = 0;


};
#pragma pack(pop)
}