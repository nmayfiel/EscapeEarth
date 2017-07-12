#include "draw.hpp"

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

void	scaleImageToImage(Image *dest, Image *src)
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

void draw(GameData *game)
{
	drawRectangle(&game->gameImage, game->P1.x, game->P1.y);
	scaleImageToImage(&game->winImage, &game->gameImage);
	mlx_put_image_to_window(game->mlx, game->win, game->winImage.ptr, game->winWidth / 2 - game->winImage.width / 2, game->winHeight / 2 - game->winImage.height / 2);
}
