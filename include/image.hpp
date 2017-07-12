#ifndef IMAGE_HPP
# define IMAGE_HPP

#include "helpers.hpp"

typedef struct s_image
{
  void *ptr;
  int *data;
  int	height;
  int	width;
  int size_in_pixels;
  int size_in_bytes;
  int size_line;
  int bpp;
  int endian;
  int center[2];
}             t_image;

#endif
