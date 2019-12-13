#include "lev.h"

lev::cReceive::cReceive()
{
}

lev::cReceive::~cReceive()
{
}

/** BUFF_SIZE 이상의 패킷 데이터가 전송되어 오면 반복해서 read 수행.**/
bool lev::cReceive::receive(int _fd)
{
	int						error = 0;

	size_t					read_size = 0;							// read 함수를 호출했을 때 읽어들인 데이터의 크기
	size_t					total_read_size = 0;					// 현재까지 읽어들인 데이터의 크기
	size_t					data_size = 0;							// 전체 데이터의 크기.

	receive_packet			packet;
	
	char*					data;
	cStream					stream;

	bzero(packet.m_packet, sizeof(packet.m_packet));
	read_size				= read(_fd, &packet.m_packet, sizeof(packet.m_packet));

	if (errno == EAGAIN)
	{
		return SUCC;
	}

	if (read_size > 0)
	{
		// 데이터 사이즈 파싱.
		if ((data_size = get_data_size(packet.m_packet)) <= 0)
		{
			cLog::get_instance()->write("LEV_ERROR", "[%d] packet size is 0\n", _fd);
			return FAIL;
		}

		// 메모리 할당 및 현재 읽어들인 데이터 사이즈 계산.
		data				= (char*)cAllocator::get_instance()->alloc(data_size);
		total_read_size		+= read_size - sizeof(size_t);
		bzero(data, data_size);

		// 데이터 적재.
		stream.set_buffer(data);
		stream.write(packet.m_packet + sizeof(size_t), read_size - sizeof(size_t));

		// 총 읽은 패킷 사이즈의 크기가 패킷의 전체 사이즈보다 작으면 아직 읽을 내용이 더 있다는 뜻으로 반복해서 read함수 호출.
		while (total_read_size < data_size)
		{

		}

		return SUCC;
	}

	//// 총 읽은 패킷 사이즈의 크기가 패킷의 전체 사이즈보다 작으면 아직 읽을 내용이 더 있다는 뜻으로 반복해서 read함수 호출.
	//while (total_read_size < data_size)
	//{
	//	error				= (int)aio_read64(&aio);
	//	if (error < 0)
	//		return FAIL;

	//	if (aio_return64(&aio) <= 0)
	//		return FAIL;

	//	read_size			= aio_return64(&aio);
	//	total_read_size		+= read_size;
	//	stream.write(packet.m_packet, read_size);
	//}

	// 리시브 큐에 data push.

	return SUCC;
}

size_t lev::cReceive::get_data_size(char* _packet)
{
	return (*(size_t*)_packet);
}