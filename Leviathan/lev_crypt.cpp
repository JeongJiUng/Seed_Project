#include "lev.h"

bool lev::cCrypt::encrypt(char* _source, char* _destination, int _length)
{
	int						key = KEY;

	if (!_source || !_destination || _length <= 0)
		return FAIL;

	for (int i = 0; i < _length; i++)
	{
		_destination[i]		= (char)((int)_source[i] ^ key >> 8);
		key					= (_destination[i] + key) * C1 + C2;
	}

	return SUCC;
}

bool lev::cCrypt::decrypt(char* _source, char* _destination, int _length)
{
	char					previousBlock;
	int						key = KEY;

	if (!_source || !_destination || _length <= 0)
		return FAIL;

	for (int i = 0; i < _length; i++)
	{
		previousBlock		= _source[i];
		_destination[i]		= (char)((int)_source[i] ^ key >> 8);
		key					= (previousBlock + key) * C1 + C2;
	}

	return SUCC;
}
