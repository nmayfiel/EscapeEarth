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

	
	// bool	updated;
	void	Loop(void);
	void	updateTime(void);
	double	currentTime(void);
 	void	setLoopHook(int (*f)(void *));
	void	setKeyDownHook(int (*function)(int, void *));
	void	setKeyUpHook(int (*function)(int, void *));
	void	setCloseHook(int (*function)(void *));

	static const float	aspectRatio;
	static const int32_t	gameSpaceWidth;
	static const int32_t	gameSpaceHeight;

	void	*mlx;
	void	*win;
	int32_t winWidth;
	int32_t winHeight;
	Clock	clock;
	t_input input;
	t_image gameImage;
	t_image winImage;
	Player	P1;
	
	// NOTE(Anthony): Are you sure about the "void *mlx" being private?

	// NOTE(Nick): It's typical for most variables in a class to be private,
	//  and get/set them with functions, otherwise why not use a struct?
	// If we design this properly, you will only need to use it from within
	// the class itself
};

#endif
