#ifndef MLX_MANAGER_HPP
# define MLX_MANAGER_HPP

#include <string>
#include <cstdint>

struct MlxManager
{
private:
	void *mlx;
	void *win;
public:
	void	init(void);
	void	newWindow(int width, int height, const std::string name);
	void	*&getMlx(void);
	void	*&getWin(void);
	void	setKeyDownHook(int (*f)(int, void *), void *data);
	void	setKeyUpHook(int (*f)(int, void *), void *data);
	void	setLoopHook(int (*f)(void *), void *data);
	void	setCloseHook(int (*f)(void *), void *data);
	void	setMouseMoveHook(int (*f)(int, int, int, void*), void *data);
	void	setMouseClickHook(int (*f)(int, int, int, void*), void *data);
	void	startLoop();
};

#endif
