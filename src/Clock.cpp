#include "Clock.hpp"
#include "helpers.hpp"
#include <mach/mach_time.h>

Clock::Clock(void): globalTime(0.0), lastFrameDuration(0.0), lastUpdate(0) {}

void	Clock::tick(void)
{
	uint64_t	now;

	now = mach_absolute_time();
	lastFrameDuration = secondsPerFrame(lastUpdate, now);
	if (lastFrameDuration < 1.0)
		globalTime += lastFrameDuration;
	lastUpdate = now;
}

