#pragma once
namespace lev
{
#pragma pack(push, 1)
class cClient : public cSocket
{
public:
	cClient();
	cClient(int _fd, string _ip);
	virtual ~cClient();

private:
	bool					m_heart_beat;
	char*					m_message;

public:
	void					set_client(bool _keep_alive, int _fd, string _ip);
	void					set_message(char* _message);

	bool					get_heart_beat();
};
#pragma pack(pop)
}