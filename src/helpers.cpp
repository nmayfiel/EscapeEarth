#include <mach/mach_time.h>
#include "image.hpp"

double		secondsPerFrame(uint64_t last, uint64_t current)
{
	static mach_timebase_info_data_t tb;
	uint64_t elapsed;
	uint64_t nanosecs;

	elapsed = current - last;
	if (tb.denom == 0)
		mach_timebase_info(&tb);
	nanosecs = elapsed * tb.numer / tb.denom;
	return ((double)nanosecs * 1.0E-9);
}

void		clear_image(Image *img, int32_t color)
{
	int32_t *buffer;

	buffer = (int32_t *)img->data;
	for (int i = 0; i < img->size_in_pixels; ++i)
		buffer[i] = color;
}
