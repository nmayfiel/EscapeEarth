#ifndef GAMEDATA_HPP
# define GAMEDATA_HPP

#include "Clock.hpp"
#include "../src/Classes/player/Player.hpp"
#include <string>

class		GameData
{
public:
	GameData(std::string winName, int32_t width, int32_t height);
	Player	P1;
	bool	updated;
	void	Loop(void);
	void	updateTime(void);
	double	currentTime(void);
 	void	setLoopHook(int (*f)(void *));
	void	SetKeyHook(int (*function)(int, GameData *));
//	int		key_press_hook(int keycode, GameData *Game);
	void	*mlx;
	void	*win;
	Clock	clock;

	//NOTE(Anthony): Are you sure about the "void *mlx" being private?
};

#endif
