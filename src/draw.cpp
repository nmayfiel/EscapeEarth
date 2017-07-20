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

void	drawRectangleOfSize(Image *img, float2 pos2, int size)
{
	int32_t *buff;
	int32_t row;
	int32_t col;
	int32_t pos;
	int32_t width = size;
	int32_t height = size;

	pos2.x -= width / 2;
	buff = (int32_t *)img->data;
	for (row = pos2.y; row < pos2.y + height; ++row)
	{
		for (col = pos2.x; col < pos2.x + width; ++col)
		{
			pos = col + (img->width * row);
			if (pos >= 0
			    && pos < img->size_in_pixels
			    && col >= 0
			    && col < img->width
			    && row >= 0
			    && row < img->height)
				buff[col + (img->width * row)] = 0x000000FF;
		}
	}
}


void	drawRectangle(Image *img, float x, float y)
{
	int32_t *buff;
	int32_t row;
	int32_t col;
	int32_t pos;
	int32_t width = 234;
	
	x -= width / 2;
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

void	drawBackground(Image *src, Image *dest, int yoffset)
{
	int32_t *dbuff;
	int32_t *sbuff;
	
	dbuff = (int32_t *)dest->data;
	sbuff = (int32_t *)src->data;
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

void draw(GameData *game)
{
	static int offset = 0;
	mlx_clear_window(game->mlx.getMlx(), game->mlx.getWin());
	clear_image(&game->gameImage, 0x00990099);

	drawBackground(&game->images[0], &game->gameImage, offset);

	drawRectangle(&game->gameImage, game->P1->position.x, game->P1->position.y);
	
	for (uint32_t i = 0; i < game->pm.count; i++)
	{
		bool swap;
		Projectile bullet;
		do {
			bullet = game->pm.projectiles[i];
			swap = false;
			if (bullet.isAlive
			    && (bullet.position.x < 0
				|| bullet.position.x > game->gameImage.width
				|| bullet.position.y < 0
				|| bullet.position.y > game->gameImage.height))
			{
				swap = true;
				game->pm.killAtIndex(i);
			}
		} while (swap);
	}
	for (uint32_t i = 0; i < game->pm.count; i++)
	{
		drawRectangleOfSize(&game->gameImage, game->pm.projectiles[i].position, 20);
	}
//	if (game->pm.projectiles[39].isAlive)
		
	nix_put_image_to_window(game->mlx.getMlx(), game->mlx.getWin(), game->gameImage.ptr, game->winSize.x / 2 - game->gameImage.center.x, game->winSize.y / 2 - game->gameImage.center.y, game->gameImage.scale.x, game->gameImage.scale.y);

	std::stringstream framerate;
	framerate << game->clock.lastFrameTime;
	std::string framestr = framerate.str();
	char *framecstr = new char[framestr.length()];
	std::strcpy(framecstr, framestr.c_str());
	mlx_string_put(game->mlx.getMlx(), game->mlx.getWin(), game->winSize.x - 120, game->winSize.y - 30, 0x00EEEEEE, framecstr);
	offset++;
}
