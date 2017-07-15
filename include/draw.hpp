#ifndef DRAW_HPP
# define DRAW_HPP

#include "GameData.hpp"
#include "helpers.hpp"
#include <mlx.h>

struct   Image;
class GameData;
class Player;
class projectile;

void    draw(GameData *Game, Projectile *projectile, Player *player);
void    appendImage(Image *src, Image *dst, float x, float y);
void    drawProjectiles(GameData *Game);

#endif
