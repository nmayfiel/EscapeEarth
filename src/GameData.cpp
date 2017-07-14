#include "Clock.hpp"
#include "GameData.hpp"
#include <mlx.h>
#include "image.hpp"
#include "MlxManager.hpp"

const float GameData::aspectRatio = 16.0 / 9.0;
const int32_t GameData::gameSpaceWidth = 768;
const int32_t GameData::gameSpaceHeight = 1366;

void	GameData::setWidthHeight(int w, int h)
{
	winWidth = w;
	winHeight = h;
}

GameData::GameData(void*& mlxptr, void*& winptr, Clock &c, int32_t width, int32_t height):
	mlx(mlxptr), win(winptr), clock(c)
{
	setWidthHeight(width, height);
	input = (t_input){};

	// set up game image
	int gameSpaceWidth = 768;
	int gameSpaceHeight = 1366;
	gameImage = (Image){};
	gameImage.width = gameSpaceWidth;
	gameImage.height = gameSpaceHeight;
	gameImage.ptr = mlx_new_image(mlx, gameSpaceWidth, gameSpaceHeight);
	gameImage.data = (int8_t *)mlx_get_data_addr(gameImage.ptr,
						     &gameImage.bpp,
						     &gameImage.size_line,
						     &gameImage.endian);
	gameImage.size_in_pixels = gameSpaceWidth * gameSpaceHeight;
	gameImage.size_in_bytes = gameImage.size_line * gameSpaceHeight;
	gameImage.center.x = gameSpaceWidth / 2;
	gameImage.center.y = gameSpaceHeight / 2;

	int winImageWidth;
	int winImageHeight;
	if ((float)winHeight / (float)winWidth > aspectRatio)
	{
		winImageWidth = winWidth;
		winImageHeight = (float)winWidth * aspectRatio;
	}
	else
	{
		winImageWidth = (float)winHeight / aspectRatio;
		winImageHeight = winHeight;
	}
	winImage = (Image){};
	winImage.width = winImageWidth;
	winImage.height = winImageHeight;
	winImage.ptr = mlx_new_image(mlx, winImageWidth, winImageHeight);
	winImage.data = (int8_t *)mlx_get_data_addr(winImage.ptr,
						     &winImage.bpp,
						     &winImage.size_line,
						     &winImage.endian);
	winImage.size_in_pixels = winImageWidth * winImageHeight;
	winImage.size_in_bytes = winImage.size_line * winImageHeight;
	winImage.center.x = winImageWidth / 2;
	winImage.center.y = winImageHeight / 2;

}

void	GameData::updateTime(void) { clock.tick(); }

double	GameData::currentTime(void) { return (clock.globalTime);}

void	GameData::setImages(Image *imgs)
{
	images = imgs;
}
