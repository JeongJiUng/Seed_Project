#include "lev.h"

long lev::get_tick()
{
	struct timeval tick;
	gettimeofday(&tick, 0);
	return (tick.tv_sec*1000 + tick.tv_usec/1000);
}
