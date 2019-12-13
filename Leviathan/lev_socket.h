#pragma once

namespace lev
{
enum SocketType
{
	TCP = 0,
	UDP
};

typedef struct socket_info
{
	int						fd;
	string					ip;
}SOCKET_INFO;

class cSocket
{
public:
	cSocket();
	cSocket(int _fd);
	cSocket(SocketType _type);
	virtual ~cSocket();

private:
	int						m_fd;

public:
	void					close();
	void					bind(const cEndpoint& _endpoint);
	void					listen(int _back_log);
	bool					accept(SOCKET_INFO& _accepted_socket);
	void					connect(const cEndpoint& _endpoint);

	void					set_fd(int _fd);

	int						get_fd();
};
}