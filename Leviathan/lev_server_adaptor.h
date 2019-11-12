#pragma once
namespace lev
{
class cServerAdaptor : public cEpollServer
{
public:
	cServerAdaptor();
	virtual ~cServerAdaptor();

public:
	virtual void			server_data_save() = 0;
};
}