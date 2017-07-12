#include "ship.hpp"

int		Ship::speed = 1;
int		Ship::x = 100;
int		Ship::y = 100;

Ship::Ship(void)
{
    return ;
}

Ship::ShipMove()
{
	//read this->pattern;
  this->y += this->speed;
}

Ship::InitProjectile(float velocity, int tx_index, int damage, GameData *game){
  game->entity[game->entity.total].x = this->x;
  game->entity[game->entity.total].y = this->y;
  game->entity[game->entity.total].velocity = velocity;
  game->entity[game->entity.total].tx_index = tx_index;
  game->entity[game->entity.total].damage = damage;
};

Ship::ShipDraw(int tx_index, t_image *img, t_image *src, int x, int y)
{
	int width = this->width;
	int height = this->height;
	int *data;
	int *src_data;
	int i;
	int si;
	int sx;
	int sy;
	int x2;
	int y2;

	data = (int *)img->data;
	src_data = (int *)src->data;
	y2 = 0;
	while (y2 < height)
	{
		x2 = 0;
		while (x2 < width)
		{
			if (x + x2 < img->width && x + x2 >= 0 && y + y2 >= 0 && y + y2 < img->height)
			{
				i = (x + x2) + (img->width * (y + y2));
				sx = this->texture[ship_index].x + (((float)x2 / (float)width) * this->texture[ship_index].width);    //ship->x - (ship->width/2);
				sy = this->texture[ship_index].y + (((float)y2 / (float)height) * this->texture[ship_index].height);  //ship->y - (ship->height/2);
				si = sx + (sy * src->width);
				if (!(src_data[si] & 0xFF000000) && i < img->size_in_pixels && i >= 0 && si < src->size_in_pixels && si >= 0)
					data[i] = src_data[si];
			}
			++x2;
		}
		++y2;
	}
}

Ship::~Ship(void)
{
    return ;
}
