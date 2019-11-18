namespace lev
{
	template<typename T>
	bool cStream::read(T* _data, size_t _length)
	{
		memcpy(_data, m_buffer_pointer + m_length, _length);
		m_length			+= _length;

		return SUCC;
	}

	template<typename T>
	bool cStream::write(T _data, size_t _length)
	{
		memcpy(m_buffer_pointer + m_length, &_data, _length);
		m_length			+= _length;

		return SUCC;
	}
}