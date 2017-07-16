#include <mlx.h>
#include "MlxManager.hpp"
#include <cstdint>

void	MlxManager::init(void) { mlx = mlx_init(); }

void	MlxManager::newWindow(int width, int height, const std::string name)
{
	char *cWinName = new char[name.length()];
	std::strcpy(cWinName, name.c_str());
	win = mlx_new_window(mlx, width, height, cWinName);
	delete [] cWinName;
}

void	*&MlxManager::getMlx(void) { return (mlx); }

void	*&MlxManager::getWin(void) { return (win); }

void	MlxManager::setKeyDownHook(int (*f)(int, void*), void *data)
{
	mlx_key_down(win, f, data);
}

void 	MlxManager::setKeyUpHook(int (*f)(int, void*), void *data)
{
	mlx_key_up(win, f, data);
}

void	MlxManager::setLoopHook(int (*f)(void *), void *data)
{
	mlx_loop_hook(mlx, f, data);
}

void	MlxManager::setCloseHook(int (*f)(void *), void *data)
{
	mlx_close_hook(win, f, data);
}

void	MlxManager::setMouseMoveHook(int (*f)(int, int, int, void *), void *data)
{
	mlx_mouse_moved_hook(win, f, data);
}

void	MlxManager::setMouseClickHook(int (*f)(int, int, int, void *), void *data)
{
	mlx_mouse_click_hook(win, f, data);
}

void	MlxManager::startLoop(void){ mlx_loop(mlx);}
