#include "lev.h"

lev::cJson::cJson()
{
}

lev::cJson::cJson(string _json_dir)
{
	open_json_file(_json_dir);
}

lev::cJson::~cJson()
{
}

bool lev::cJson::open_json_file(string _json_dir)
{
	ifstream				option_doc(_json_dir, ifstream::binary);

	try
	{
		option_doc >> m_value;
	}
	catch (Json::Exception const&)
	{
		// TODO:: PRINT LOG
		printf("error\n");
		return FAIL;
	}

	return SUCC;
}

Json::Value& lev::cJson::get_data(string _key)
{
	return m_value[_key];
}
