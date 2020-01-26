#pragma once
namespace lev
{
const int					C1 = 52845;
const int					C2 = 22719;
const int					KEY = 72957;

class cCrypt
{
public:
	static bool				encrypt(char* _source, char* _destination, int _length);
	static bool				decrypt(char* _source, char* _destination, int _length);
};
}