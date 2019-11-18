#include "lev.h"

lev::cRandom::cRandom()
{
}

lev::cRandom::cRandom(unsigned int _seed)
{
	init(_seed);
}

lev::cRandom::~cRandom()
{
}

void lev::cRandom::init(unsigned int _seed)
{
	m_seed					= _seed;
}

int lev::cRandom::rand()
{
	return (((m_seed = m_seed * 214013L + 2531011L) >> 16) & 0x7FFF);
}

int lev::cRandom::simple_random()
{
	return (((m_seed = m_seed * 2531011L) >> 3) & 0x7FFF);
}

int lev::cRandom::complex_random()
{
	unsigned int			next = m_seed;
	int						result;
	
	next					*= 1103515245;
	next					+= 12345;
	result					= (unsigned int)(next / 65536) % 2048;

	next					*= 1103515245;
	next					+= 12345;
	result					<<= 10;
	result					^= (unsigned int)(next / 65536) % 1024;

	next					*= 1103515245;
	next					+= 12345;
	result					<<= 10;
	result					^= (unsigned int)(next / 65536) % 1024;

	m_seed					= next;
	return result;
}
