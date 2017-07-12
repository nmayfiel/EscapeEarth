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
  int   tx_index;
  //NOTE(mick) Put entity in gameData and make this value correspond to game->entity->texture[tx_index]
  Movement pattern;

  ShipMove();
  InitProjectile(float velocity, int tx_index, int damage, GameData *game);
  ShipDraw(int tx_index, t_image *img, t_image *src, int x, int y);
};

class entity{

  Entity();
  ~Entity();

  DrawEntity(int tx_index, t_image *src, int x, int y, GameData *Game);
}

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
