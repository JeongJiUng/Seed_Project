#pragma once
namespace lev
{
#pragma pack(push, 1)
typedef struct __receive_packet
{
	char					m_packet[BUFF_SIZE];
}receive_packet;

class cReceive
{
public:
	cReceive();
	virtual ~cReceive();

public:
	bool					receive(int _fd);

	size_t					get_data_size(char* _packet);
};
#pragma pack(pop)
}