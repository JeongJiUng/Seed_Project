#pragma once
namespace lev
{
class cStream
{
public:
	cStream();
	virtual ~cStream();

private:
	char*					m_buffer_pointer;
	size_t					m_length;

public:
	bool					set_buffer(char* _buffer);
	size_t					get_length();

	template<typename T>
	bool					read(T* _data, size_t _length = sizeof(T));
	bool					read_int32(int* _data, size_t _length = sizeof(int));
	bool					read_int64(int64_t* _data, size_t _length = sizeof(int64_t));
	bool					read_char(char* _data, size_t _length = sizeof(char));
	bool					read_float(float* _data, size_t _length = sizeof(float));
	bool					read_ushort(ushort* _data, size_t _length = sizeof(ushort));
	bool					read_short(short* _data, size_t _length = sizeof(short));

	template<typename T>
	bool					write(T _data, size_t _length = sizeof(T));
	bool					write_int32(int _data, size_t _length = sizeof(int));
	bool					write_int64(int64_t _data, size_t _length = sizeof(int64_t));
	bool					write_char(char _data, size_t _length = sizeof(char));
	bool					write_float(float _data, size_t _length = sizeof(float));
	bool					write_ushort(ushort _data, size_t _length = sizeof(ushort));
	bool					write_short(short _data, size_t _length = sizeof(short));
};
}

#include "lev_stream.inl"