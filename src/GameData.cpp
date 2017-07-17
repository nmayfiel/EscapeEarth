#include "vec.hpp"
#include "Clock.hpp"
#include "GameData.hpp"
#include <mlx.h>
#include "image.hpp"
#include "MlxManager.hpp"

const float GameData::aspectRatio = 16.0 / 9.0;
const int32_t GameData::gameSpaceWidth = 768;
const int32_t GameData::gameSpaceHeight = 1366;

GameData::GameData(MlxManager &mlx, Clock &c, int2 &size): mlx(mlx), clock(c), winSize(size)
{
	input = (t_input){};

	// set up game image
	int gameSpaceWidth = 768;
	int gameSpaceHeight = 1366;
	gameImage = (Image){};
	gameImage.width = gameSpaceWidth;
	gameImage.height = gameSpaceHeight;

	float xscale;
	float yscale;
	if ((float)winSize.y / (float)winSize.x > aspectRatio)
	{
		xscale = 1.0 / ((float)gameSpaceWidth / (float)winSize.x);
		yscale = xscale;
	}
	else
	{
		yscale = 1.0 / ((float)gameSpaceHeight / (float)winSize.y);
		xscale = yscale;

	}
	gameImage.scale = float2(xscale, yscale);
	gameImage.ptr = mlx_new_scaled_image(mlx.getMlx(), gameSpaceWidth, gameSpaceHeight, xscale, yscale);
	gameImage.data = (int8_t *)mlx_get_data_addr(gameImage.ptr,
						     &gameImage.bpp,
						     &gameImage.size_line,
						     &gameImage.endian);
	gameImage.size_in_pixels = gameSpaceWidth * gameSpaceHeight;
	gameImage.size_in_bytes = gameImage.size_line * gameSpaceHeight;
	gameImage.center.x = ((float)gameSpaceWidth * gameImage.scale.x) / 2;
	gameImage.center.y = ((float)gameSpaceHeight * gameImage.scale.y) / 2;
}

void	GameData::updateTime(void) { clock.tick(); }

double	GameData::currentTime(void) { return (clock.globalTime);}

void	GameData::setImages(Image *imgs)
{
	images = imgs;
}
