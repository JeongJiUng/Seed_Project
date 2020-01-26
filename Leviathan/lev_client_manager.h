#pragma once
namespace lev
{
#pragma pack(push, 1)
class cClientManager : public cSingleton<cClientManager>, public cMultiThreadSync<cClientManager>
{
public:
	cClientManager();
	virtual ~cClientManager();

private:
	vector<cClient*>		m_clts;

public:
	void					begin(int _max_clt_count, int _listen_socket);
	void					insert(SOCKET_INFO _clt);
};
#pragma pack(pop)
}