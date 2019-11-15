#pragma once
namespace lev
{
class cLog : public cSingleton<cLog>
{
public:
	cLog();
	virtual ~cLog();

private:
	unordered_map<string, string>	m_log_map;	// 맵을 사용하여 로그 이름과 경로 관리.

public:
	void					load_log_option(cJson _json);
	void					set_log(string _key, string _log_dir);	// 로그가 저장될 위치와 이름(key)를 정해서 로그 맵에 저장.
	bool					write(string _key, const char *_data, ...);
};
}