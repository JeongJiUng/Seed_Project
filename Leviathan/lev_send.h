#pragma once
namespace lev
{
typedef struct __send_packet
{
	char*					m_packet;
}send_packet;

class cSend
{
public:
	cSend();
	virtual ~cSend();

public:
	bool					send(int _fd, char* _data, size_t _size);
};
}