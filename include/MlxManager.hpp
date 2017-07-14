#ifndef MLX_MANAGER_HPP
# define MLX_MANAGER_HPP

#include <string>
#include <cstdint>

struct MlxManager
{
	static void	*init(void);
	static void	*newWindow(void *mlxPtr, int width, int height, const std::string name);
	static void	setKeyDownHook(void *win, int (*f)(int, void *), void *data);
	static void	setKeyUpHook(void *win, int (*f)(int, void *), void *data);
	static void	setLoopHook(void *mlx, int (*f)(void *), void *data);
	static void	setCloseHook(void *win, int (*f)(void *), void *data);
	static void	setMouseMoveHook(void *win, int (*f)(int, int, int, void*), void *data);
	static void	setMouseClickHook(void *win, int (*f)(int, int, int, void*), void *data);
	static void	startLoop(void *mlx);
};

#endif
