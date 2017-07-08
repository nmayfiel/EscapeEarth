#ifndef CLOCK_HPP
# define CLOCK_HPP

#include <cstdint>

struct		Clock
{
	double		globalTime;
	double		lastFrameTime;
	uint64_t	lastUpdate;

	void	tick(void);

	Clock(void);
};

#endif
