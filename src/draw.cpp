#include "draw.hpp"
#include <sstream>

void	putPixelToImage(Image *img, float x, float y)
{
	int32_t *buffer;
	int32_t pos;

	buffer = (int32_t *)img->data;
	if (y > 0 && x > 0 && y < img->height && y < img->width)
	{
			pos = x + (img->width * y);
		buffer[pos] = 0x0000FF00;
	}
}

void	drawRectangle(Image *img, float x, float y)
{
	int32_t *buff;
	int32_t row;
	int32_t col;
	int32_t pos;

	buff = (int32_t *)img->data;
	for (row = y; row < y + 170; ++row)
	{
		for (col = x; col < x + 234; ++col)
		{
			pos = col + (img->width * row);
			if (pos >= 0
			    && pos < img->size_in_pixels
			    && col >= 0
			    && col < img->width
			    && row >= 0
			    && row < img->height)
				buff[col + (img->width * row)] = 0x0000FF00;
		}
	}
}

void	scaleImageToImage(Image *src, Image *dest)
{
	int32_t *dbuff;
	int32_t *sbuff;
	int desty;
	int destx;
	int srcy;
	int srcx;

	dbuff = (int32_t *)dest->data;
	sbuff = (int32_t *)src->data;
	for (int i = 0; i < dest->size_in_pixels; ++i)
	{
		destx = i % dest->width;
		desty = i / dest->width;

		srcy = (float)src->height * ((float)desty / (float)dest->height);
		srcx = (float)src->width * ((float)destx / (float)dest->width);
		int srci = (srcy * src->width) + srcx;

		dbuff[i] = sbuff[srci];
	}
}

void 	drawProjectiles(Image *src, Image *dst, float x, float y)
{
	appendImage(src, dst, x, y);
}

void    appendImage(Image *src, Image *dst, float x, float y)
{
    int32_t     *src_buff;
    int32_t     *dst_buff;
    int         di, si = 0;

    src_buff = (int32_t *)src->data;
    dst_buff = (int32_t *)dst->data;
    di = dst->width * y + (x - src->width / 2);
    while (si < src->size_in_pixels)
    {
        if (si != 0 && si % src->width == 0)
            di += dst->width - src->width;
        if (!(src_buff[si] & 0xFF000000) && si < src->size_in_pixels
            && di < dst->size_in_pixels)
                dst_buff[di] = src_buff[si];
        si++;
        di++;
    }
}

void    drawplayer(Image *src, Image *dst, float x, float y)
{

    // NOTE(Anthony) : Do not touch
    appendImage(src, dst, x, y);
}

void	drawBackground(Image *src, Image *dest, int yoffset)
{
	int32_t *dbuff;
	int32_t *sbuff;

	dbuff = (int32_t *)dest->data;
	sbuff = (int32_t *)src->data;
// get the starting y value for the value
	yoffset %= src->height;
	yoffset = src->height - yoffset;
	int si = src->width * yoffset - 1;
	for (int i = 0; i < dest->size_in_pixels; ++i, ++si)
	{
		if (si > src->size_in_pixels)
			si = 0;
		dbuff[i] = sbuff[si];
	}
}

void draw(GameData *game, Projectile *projectile, Player *player)
{
	static int offset = 0;
	mlx_clear_window(game->mlx, game->win);
	clear_image(&game->gameImage, 0x00990099);

	drawBackground(&game->images[0], &game->gameImage, offset);
    if (game->nb_ammo > -1){
        for (int i = 0 ; i < game->nb_ammo ; i++){
            std::cout << projectile[i].x << " " << projectile[i].y << std::endl;
            drawProjectiles(&game->images[4], &game->gameImage, projectile[i].x, projectile[i].y);
        }
    }
    drawplayer(&game->images[3], &game->gameImage, player->x, player->y);
	putPixelToImage(&game->gameImage, player->x, player->y);
    scaleImageToImage(&game->gameImage, &game->winImage);

	mlx_put_image_to_window(game->mlx, game->win, game->winImage.ptr, game->winWidth / 2 - game->winImage.width / 2, game->winHeight / 2 - game->winImage.height / 2);

	std::stringstream framerate;
	framerate << game->clock.lastFrameTime;
	std::string framestr = framerate.str();
	char *framecstr = new char[framestr.length()];
	std::strcpy(framecstr, framestr.c_str());
	mlx_string_put(game->mlx, game->win, G_WIDTH - 120, G_HEIGHT - 30, 0x00EEEEEE, framecstr);
	offset++;
	//mlx_put_image_to_window(game->mlx, game->win, game->images[0].ptr, 0, 0);
}
