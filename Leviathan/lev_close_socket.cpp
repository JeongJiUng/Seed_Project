#include "lev.h"

void lev::cCloseSocket::close(int _fd)
{
	::close(_fd);
}