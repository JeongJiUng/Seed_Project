#include "lev.h"

lev::cStream::cStream()
{
	m_buffer_pointer		= NULL;
	m_length				= 0;
}

lev::cStream::~cStream()
{

}

bool lev::cStream::set_buffer(char* _buffer)
{
	if (!_buffer)
		return FAIL;

	m_buffer_pointer		= _buffer;
	m_length				= 0;

	return false;
}

size_t lev::cStream::get_length()
{
	return m_length;
}

bool lev::cStream::read_int32(int* _data, size_t _length)
{
	return read(_data, _length);
}

bool lev::cStream::read_int64(int64_t* _data, size_t _length)
{
	return read(_data, _length);
}

bool lev::cStream::read_char(char* _data, size_t _length)
{
	return read(_data, _length);
}

bool lev::cStream::read_float(float* _data, size_t _length)
{
	return read(_data, _length);
}

bool lev::cStream::read_ushort(ushort* _data, size_t _length)
{
	return read(_data, _length);
}

bool lev::cStream::read_short(short* _data, size_t _length)
{
	return read(_data, _length);
}

bool lev::cStream::write_int32(int _data, size_t _length)
{
	return write(_data, _length);
}

bool lev::cStream::write_int64(int64_t _data, size_t _length)
{
	return write(_data, _length);
}

bool lev::cStream::write_char(char _data, size_t _length)
{
	return write(_data, _length);
}

bool lev::cStream::write_float(float _data, size_t _length)
{
	return write(_data, _length);
}

bool lev::cStream::write_ushort(ushort _data, size_t _length)
{
	return write(_data, _length);
}

bool lev::cStream::write_short(short _data, size_t _length)
{
	return write(_data, _length);
}

lev::cStreamManager::cStreamManager()
{
	m_stream				= new cStream();//(cStream*)cAllocator::get_instance()->alloc(sizeof(cStream));
}

lev::cStreamManager::~cStreamManager()
{
	//cAllocator::get_instance()->dealloc(m_stream);
	delete m_stream;
}

cStream* lev::cStreamManager::operator->()
{
	return m_stream;
}

lev::cStreamManager::operator cStream* ()
{
	return m_stream;
}
