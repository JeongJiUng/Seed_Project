#pragma once
namespace lev
{
#pragma pack(push, 1)
class cClient
{
public:
	cClient();
	cClient(int _fd, string _ip);
	virtual ~cClient();

private:
	char*					m_message;

	string					m_ip;
	int						m_fd;

public:
	void					set_client(int _fd, string _ip);
	void					set_message(char* _message);
};
#pragma pack(pop)
}