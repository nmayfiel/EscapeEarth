#pragma once

#include <cstdint>

struct		Clock
{
	Clock(void);

	double		globalTime;
	double		lastFrameDuration;
	uint64_t	lastUpdate;

	void	tick(void);
};
