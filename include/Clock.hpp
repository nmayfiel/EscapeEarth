#pragma once

#include <cstdint>

struct		Clock
{
	double		globalTime;
	double		lastFrameTime;
	uint64_t	lastUpdate;

	void	tick(void);

	Clock(void);
};
