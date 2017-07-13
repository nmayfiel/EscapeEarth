#include "GameData.hpp"

Clock::Clock(void)
{
	globalTime = 0.0;
	lastFrameTime = 0.0;
	lastUpdate = 0;
}

void	Clock::tick(void)
{
	uint64_t	now;

	now = mach_absolute_time();
	lastFrameTime = secondsPerFrame(lastUpdate, now);
	if (lastFrameTime < 1.0)
		globalTime += lastFrameTime;
	lastUpdate = now;
}

