#ifndef IMAGE_HPP
# define IMAGE_HPP

#include <stdint.h>
#include "vec.hpp"

typedef struct s_point
{
	int32_t x;
	int32_t y;
}		t_point;

struct		Image
{
	void	*ptr;
	int8_t	*data;
	int32_t	bpp;
	int32_t	size_line;
	int32_t	size_in_bytes;
	int32_t	size_in_pixels;
	int32_t	endian;
	int32_t	height;
	int32_t	width;
	t_point	center;
	float2 scale;

	void	getImageFromData(void *mlx, const uint8_t *imgData, uint32_t size);
};

#endif
