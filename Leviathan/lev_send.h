#pragma once
namespace lev
{
#pragma pack(push, 1)
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
#pragma pack(pop)
}