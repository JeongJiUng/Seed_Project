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
	unordered_map<int, cClient>	m_clts;

public:
};
#pragma pack(pop)
}