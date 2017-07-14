#include <mlx.h>
#include "MlxManager.hpp"
#include <cstdint>

void	*MlxManager::init(void) { return (mlx_init()); }

void	*MlxManager::newWindow(void *mlxPtr, int width, int height, const std::string name)
{
	char *cWinName = new char[name.length()];
	std::strcpy(cWinName, name.c_str());
	void *win = mlx_new_window(mlxPtr, width, height, cWinName);
	delete [] cWinName;
	return (win);
}

void	MlxManager::setKeyDownHook(void *win, int (*f)(int, void*), void *data)
{
	mlx_key_down(win, f, data);
}

void 	MlxManager::setKeyUpHook(void *win, int (*f)(int, void*), void *data)
{
	mlx_key_up(win, f, data);
}

void	MlxManager::setLoopHook(void *mlx, int (*f)(void *), void *data)
{
	mlx_loop_hook(mlx, f, data);
}

void	MlxManager::setCloseHook(void *win, int (*f)(void *), void *data)
{
	mlx_close_hook(win, f, data);
}

void	MlxManager::setMouseMoveHook(void *win, int (*f)(int, int, int, void *), void *data)
{
	mlx_mouse_moved_hook(win, f, data);
}

void	MlxManager::setMouseClickHook(void *win, int (*f)(int, int, int, void *), void *data)
{
	mlx_mouse_click_hook(win, f, data);
}

void	MlxManager::startLoop(void *mlx){ mlx_loop(mlx);}
