#include "lev.h"

lev::cSocket::cSocket() : m_fd(-1), m_ip("")
{
}

lev::cSocket::cSocket(int _fd) : m_fd(_fd), m_ip("")
{
}

lev::cSocket::cSocket(int _fd, string _ip) : m_fd(_fd), m_ip(_ip)
{
}

lev::cSocket::cSocket(SocketType _type)
{
	if (_type == SocketType::TCP)
		m_fd				= socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	else
		m_fd				= socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	if (m_fd < 0)
		cLog::get_instance()->write("LEV_ERROR", "[SOCKET] FAIL, ERROR CODE [%d]\n", m_fd);
}

lev::cSocket::~cSocket()
{
	close();
}

void lev::cSocket::close()
{
	// TODO:: gracefull disconnect 구현 필요.
	cout << "[" << m_fd << "] close socket" << endl;
	shutdown(m_fd, SHUT_RDWR);
	::close(m_fd);
}

void lev::cSocket::bind(const cEndpoint& _endpoint)
{
	int						error;
	if ((error = ::bind(m_fd, (sockaddr*)&_endpoint.m_ivp4_endpoint, sizeof(_endpoint.m_ivp4_endpoint))) < 0)
	{
		cLog::get_instance()->write("LEV_ERROR", "[BIND] FAIL, ERROR CODE [%d]\n", error);
	}
}

void lev::cSocket::listen(int _back_log)
{
	int						error = ::listen(m_fd, _back_log);

	if (error < 0)
	{
		cLog::get_instance()->write("LEV_ERROR", "[LISTEN] FAIL, ERROR CODE [%d]\n", error);
	}
}

bool lev::cSocket::accept(SOCKET_INFO& _accepted_socket)
{
	struct sockaddr_in		ipv4_endpoint;
	int						ipv4_endpoint_len = sizeof(ipv4_endpoint);

	_accepted_socket.fd		= ::accept(m_fd, (struct sockaddr*)&ipv4_endpoint, (socklen_t*)&ipv4_endpoint_len);
	if (_accepted_socket.fd < 0)
	{
		cLog::get_instance()->write("LEV_ERROR", "[ACCEPT] FAIL, ERROR CODE [%d]\n", _accepted_socket.fd);
		return FAIL;
	}

	_accepted_socket.ip		= inet_ntoa(ipv4_endpoint.sin_addr);

	return SUCC;
}

bool lev::cSocket::accept(int _listen_socket)
{
	struct sockaddr_in		ipv4_endpoint;
	int						ipv4_endpoint_len = sizeof(ipv4_endpoint);

	m_fd					= ::accept(_listen_socket, (struct sockaddr*)&ipv4_endpoint, (socklen_t*)&ipv4_endpoint_len);
	if (m_fd < 0)
	{
		cLog::get_instance()->write("LEV_ERROR", "[ACCEPT] FAIL, ERROR CODE [%d]\n", m_fd);
		return FAIL;
	}

	m_ip					= inet_ntoa(ipv4_endpoint.sin_addr);

	return SUCC;
}

void lev::cSocket::connect(const cEndpoint& _endpoint)
{
	if (::connect(m_fd, (sockaddr*)&_endpoint.m_ivp4_endpoint, sizeof(_endpoint.m_ivp4_endpoint)) < 0)
	{
		cout << "connect fail" << endl;
	}
}

void lev::cSocket::set_fd(int _fd)
{
	m_fd					= _fd;
}

bool lev::cSocket::set_nonblocking()
{
	u_long					val = 1;
	int						error = ioctl(m_fd, FIONBIO, &val);
	
	if (error != 0)
	{
		cLog::get_instance()->write("LEV_ERROR", "[SET NON-BLOCKING SOCEKT] FAIL\n");
		return FAIL;
	}
	
	return SUCC;
}

int lev::cSocket::get_fd()
{
	return m_fd;
}