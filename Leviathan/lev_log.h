#pragma once
namespace lev
{
class cLog : public cSingleton<cLog>
{
public:
	cLog();
	virtual ~cLog();

private:
	unordered_map<string, string>	m_log_map;	// ���� ����Ͽ� �α� �̸��� ��� ����.

public:
	void					load_log_option(cJson _json);
	void					set_log(string _key, string _log_dir);	// �αװ� ����� ��ġ�� �̸�(key)�� ���ؼ� �α� �ʿ� ����.
	bool					write(string _key, const char *_data, ...);
};
}