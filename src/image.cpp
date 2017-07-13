#include "image.hpp"
#include "mlx.h"

void	Image::getImageFromData(void *mlx, const uint8_t *imgData, uint32_t size)
{
	ptr = png_data_to_image(mlx, imgData, size, &width, &height);
	data = (int8_t *)mlx_get_data_addr(ptr,
					   &bpp,
					   &size_line,
					   &endian);
	center.x = width / 2;
	center.y = height / 2;
	size_in_pixels = width * height;
	size_in_bytes = size_line * height;
}
