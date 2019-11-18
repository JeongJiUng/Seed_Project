#pragma once
namespace lev
{
class cRandom
{
public:
	cRandom();
	cRandom(unsigned int _seed);
	virtual ~cRandom();

private:
	unsigned int			m_seed;

public:
	void					init(unsigned int _seed);

	int						rand();
	int						simple_random();
	int						complex_random();
};
}