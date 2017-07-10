#include "draw.hpp"

void draw(GameData *Game)
{
    int         x;
    int         y;

    y = 0;
    while (y < G_HEIGHT){
        x = 0;
        while (x < G_WIDTH){
            if (x == Game->P1.x && y == Game->P1.y)
                mlx_pixel_put(Game->mlx, Game->win, x, y, 0xFFFFFF);
            x++;
        }
        y++;
    }
}
