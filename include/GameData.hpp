#ifndef GAMEDATA_HPP
# define GAMEDATA_HPP

#include "Clock.hpp"
#include "Player.hpp"
#include "input.hpp"
#include "image.hpp"
#include <string>
#include <mlx.h>

class		GameData
{
public:
	GameData(std::string winName, int32_t width, int32_t height);
	Player	P1;
	// bool	updated;
	void	Loop(void);
	void	updateTime(void);
	double	currentTime(void);
 	void	setLoopHook(int (*f)(void *));
	void	setKeyDownHook(int (*function)(int, void *));
	void	setKeyUpHook(int (*function)(int, void *));
	void	setCloseHook(int (*function)(void *));
//	int		key_press_hook(int keycode, GameData *Game);
	void	*mlx;
	void	*win;
	Clock	clock;
	t_input input;
	t_image gameImage;

	//NOTE(Anthony): Are you sure about the "void *mlx" being private?
};

#endif
