#include "draw.hpp"

void	put_pixel_to_image(t_image *img, float x, float y)
{
	int32_t *buffer;
	int32_t pos;


	// TODO(nick): we need to check if this is actually drawing within
	// the bounds of the buffer, i.e. pos is > 0 and <= image size in pixels - 1
	buffer = (int32_t *)img->data;
	pos = x + (img->width * y);
	buffer[pos] = 0x0000FF00;
}

void draw(GameData *Game)
{
	put_pixel_to_image(&Game->gameImage, Game->P1.x, Game->P1.y);
	mlx_put_image_to_window(Game->mlx, Game->win, Game->gameImage.ptr, 0, 0);
}
