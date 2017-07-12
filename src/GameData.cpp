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

	clock = Clock();

	input = (t_input){};

	// set up game image
	gameImage = (t_image){};
	gameImage.width = width;
	gameImage.height = height;
	gameImage.ptr = mlx_new_image(mlx, width, height);
	gameImage.data = (int8_t *)mlx_get_data_addr(gameImage.ptr,
						     &gameImage.bpp,
						     &gameImage.size_line,
						     &gameImage.endian);
	gameImage.size_in_pixels = width * height;
	gameImage.size_in_bytes = gameImage.size_line * height;
	gameImage.center.x = width / 2;
	gameImage.center.y = height / 2;
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
