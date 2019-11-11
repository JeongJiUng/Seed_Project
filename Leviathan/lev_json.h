#pragma once
namespace lev
{
class cJson
{
public:
	cJson();
	cJson(string _json_dir);
	virtual ~cJson();

private:
	Json::Value				m_value;

public:
	bool					open_json_file(string _json_dir);
	Json::Value&			get_data(string _key);
};
}