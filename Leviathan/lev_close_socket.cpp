#include "lev.h"

void lev::cCloseSocket::close(int _fd)
{
	cLog::get_instance()->write("LEV_CONNECT", "[%d] CLOSE SOCKET\n", _fd);
	::close(_fd);
}