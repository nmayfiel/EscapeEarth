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
  float x;
  float y;
  float velocity
  Texture texture;
  Movement pattern;

  ShipMove();
  InitProjectile(float x, float y, float velocity, int tx_index, int damage, GameData *game);
  ShipDraw(int tx_index, t_image *img, t_image *src, int x, int y);
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
