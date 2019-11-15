#include "lev.h"

lev::cLog::cLog()
{
}

lev::cLog::~cLog()
{
}

void lev::cLog::load_log_option(cJson _json)
{
	auto					logs = _json.get_data("LOGS");
	
	for (int i = 0; i < (int)logs.size(); i++)
	{
		string				key = logs[i].asString();
		string				dir = _json.get_data(key).asString();
		set_log(key, dir);
	}
}

void lev::cLog::set_log(string _key, string _log_dir)
{
	m_log_map[_key]			= _log_dir;
}

bool lev::cLog::write(string _key, const char* _data, ...)
{
	char					file_name[PATH_MAX] = { 0, };
	char					date[32] = { 0, };
	char					write_date[32] = { 0, };
	FILE*					log_fd = NULL;

	if (m_log_map[_key] == "")
		return FAIL;

	time_t					raw = time(NULL);
	struct tm				*pTm = localtime(&raw);
	strftime(write_date, 32, "[%H:%M:%S] :: ", pTm);
	strftime(date, 32, "%Y-%m-%d-%H", pTm);

	snprintf(file_name, PATH_MAX, "%s_%s.log", m_log_map[_key], date);

	va_list					ap;
	va_start(ap, _data);

	if ((log_fd = fopen(file_name, "a")) == NULL)
		return FAIL;

	fprintf(log_fd, "%s", write_date);
	vfprintf(log_fd, _data, ap);

	va_end(ap);
	fclose(log_fd);
	return SUCC;
}
