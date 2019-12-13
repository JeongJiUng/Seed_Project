#include "lev.h"

lev::cReceive::cReceive()
{
}

lev::cReceive::~cReceive()
{
}

/** BUFF_SIZE �̻��� ��Ŷ �����Ͱ� ���۵Ǿ� ���� �ݺ��ؼ� read ����.**/
bool lev::cReceive::receive(int _fd)
{
	int						error = 0;

	size_t					read_size = 0;							// read �Լ��� ȣ������ �� �о���� �������� ũ��
	size_t					total_read_size = 0;					// ������� �о���� �������� ũ��
	size_t					data_size = 0;							// ��ü �������� ũ��.

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
		// ������ ������ �Ľ�.
		if ((data_size = get_data_size(packet.m_packet)) <= 0)
		{
			cLog::get_instance()->write("LEV_ERROR", "[%d] packet size is 0\n", _fd);
			return FAIL;
		}

		// �޸� �Ҵ� �� ���� �о���� ������ ������ ���.
		data				= (char*)cAllocator::get_instance()->alloc(data_size);
		total_read_size		+= read_size - sizeof(size_t);
		bzero(data, data_size);

		// ������ ����.
		stream.set_buffer(data);
		stream.write(packet.m_packet + sizeof(size_t), read_size - sizeof(size_t));

		// �� ���� ��Ŷ �������� ũ�Ⱑ ��Ŷ�� ��ü ������� ������ ���� ���� ������ �� �ִٴ� ������ �ݺ��ؼ� read�Լ� ȣ��.
		while (total_read_size < data_size)
		{

		}

		return SUCC;
	}

	//// �� ���� ��Ŷ �������� ũ�Ⱑ ��Ŷ�� ��ü ������� ������ ���� ���� ������ �� �ִٴ� ������ �ݺ��ؼ� read�Լ� ȣ��.
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

	// ���ú� ť�� data push.

	return SUCC;
}

size_t lev::cReceive::get_data_size(char* _packet)
{
	return (*(size_t*)_packet);
}