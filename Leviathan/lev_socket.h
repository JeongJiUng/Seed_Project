#pragma once
namespace lev
{
class cSocket
{
public:
	cSocket();
	virtual ~cSocket();

public:
	int						socket(int _type);
};
}