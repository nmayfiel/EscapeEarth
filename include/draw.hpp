#ifndef DRAW_HPP
# define DRAW_HPP

struct   Image;

class   GameData;

void    draw(GameData *Game);
void    appendImage(Image *src, Image *dst, float x, float y);
void    drawProjectiles(GameData *Game);

#endif
