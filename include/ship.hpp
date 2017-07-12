#ifndef SHIP_HPP
# define SHIP_HPP

#include "GameData.hpp"
#include "helpers.hpp"
#include <mlx.h>

class Ship
{
  Ship();
  ~Ship();

  bool is_alive;
  int x;
  int y;
  Texture texture[];
  Movement pattern;

  ShipMove();
  CreateProjectile();
  ShipDraw(int ship_index, t_image *img, t_image *src, int x, int y);
};

class Texture
{
  Texture();
  ~Texture();

  int width;
  int height;
	int x;
	int y;
	// int x_dir;
	// int y_dir;
};

#endif
