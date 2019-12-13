#include "lev.h"

lev::cSend::cSend()
{
}

lev::cSend::~cSend()
{
}

bool lev::cSend::send(int _fd, char* _data, size_t _size)
{
	char*					data;
	size_t					total_size;
	size_t					packet_size;
	cStream					stream;

	struct aiocb64			aio;

	packet_size				= _size + 1;
	total_size				= sizeof(size_t) + packet_size;
	data					= (char*)cAllocator::get_instance()->alloc(total_size);
	bzero(data, total_size);

	stream.set_buffer(data);
	stream.write(packet_size, sizeof(size_t));
	stream.write(_data, _size);
	stream.write('\0', 1);

	aio.aio_fildes			= _fd;
	aio.aio_nbytes			= total_size;

	return SUCC;
}