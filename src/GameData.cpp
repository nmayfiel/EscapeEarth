#include "Clock.hpp"
#include "GameData.hpp"
#include <mlx.h>

GameData::GameData(std::string winName, int32_t width, int32_t height)
{
	char *cWinName = new char[winName.length()];
	std::strcpy(cWinName, winName.c_str());
	mlx = mlx_init();
	win = mlx_new_window(mlx, width, height, cWinName);
	delete [] cWinName;
	clock = Clock();
}

void	GameData::updateTime(void) { clock.tick(); }

double	GameData::currentTime(void) { return (clock.globalTime);}

void	GameData::startLoop(void) { mlx_loop(mlx); }

void	GameData::setLoopHook(int (*funct)(void *))
{
	void *t = static_cast<void *>(this);
	mlx_loop_hook(mlx, funct, t);
}
