#include "Clock.hpp"
#include "GameData.hpp"
#include <mlx.h>
#include "image.hpp"

GameData::GameData(std::string winName, int32_t width, int32_t height)
{
	mlx = mlx_init();
	char *cWinName = new char[winName.length()];
	std::strcpy(cWinName, winName.c_str());
	win = mlx_new_window(mlx, width, height, cWinName);
	delete [] cWinName;

	winWidth = width;
	winHeight = height;
	
	clock = Clock();

	input = (t_input){};

	// set up game image
	int gameImageWidth = 768;
	int gameImageHeight = 1366;
	gameImage = (t_image){};
	gameImage.width = gameImageWidth;
	gameImage.height = gameImageHeight;
	gameImage.ptr = mlx_new_image(mlx, gameImageWidth, gameImageHeight);
	gameImage.data = (int8_t *)mlx_get_data_addr(gameImage.ptr,
						     &gameImage.bpp,
						     &gameImage.size_line,
						     &gameImage.endian);
	gameImage.size_in_pixels = gameImageWidth * gameImageHeight;
	gameImage.size_in_bytes = gameImage.size_line * gameImageHeight;
	gameImage.center.x = gameImageWidth / 2;
	gameImage.center.y = gameImageHeight / 2;

	float gameAspect = 16.0 / 9.0;
	int winImageWidth;
	int winImageHeight;
	if ((float)height / (float)width > gameAspect)
	{
		winImageWidth = width;
		winImageHeight = (float)width * 1.6;
	}
	else
	{
		winImageWidth = (float)height / 1.6;
		winImageHeight = height;
	}
	winImage = (t_image){};
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

void	GameData::Loop(void) { mlx_loop(mlx); }

void	GameData::setKeyDownHook(int (*function)(int, void*))
{
	void *t = static_cast<void *>(this);
	mlx_key_down(win, function, t);
}

void 	GameData::setKeyUpHook(int (*function)(int, void*))
{
	void *t = static_cast<void *>(this);
	mlx_key_up(win, function, t);
}

void	GameData::setLoopHook(int (*funct)(void *))
{
	void *t = static_cast<void *>(this);
	mlx_loop_hook(mlx, funct, t);
}

void	GameData::setCloseHook(int (*funct)(void *))
{
	void *t = static_cast<void *>(this);
	mlx_close_hook(mlx, funct, t);
}
