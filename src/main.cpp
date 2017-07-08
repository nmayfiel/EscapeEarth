#include <iostream>
#include <mlx.h>

int	main(void)
{
	void *mlx;
	void *win;

	mlx = mlx_init();
	std::string win_title = "Escape EARTH";
	char *str = new char[win_title.length()];
	std::strcpy(str, win_title.c_str());
	win = mlx_new_window(mlx, 768, 768, str);
	mlx_loop(mlx);
	return (0);
}
