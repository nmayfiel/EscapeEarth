#ifndef GAMEDATA_HPP
# define GAMEDATA_HPP

#include <iostream>
#include <cstdio>
#include <ctime>
#include "Projectile.hpp"
#include "helpers.hpp"
#include "Clock.hpp"
#include "input.hpp"
#include "image.hpp"
#include <string>
#include <mlx.h>
#include "draw.hpp"
#include <mach/mach_time.h>
#include <sstream>
#include "Player.hpp"

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
	void	setImages(Image *imgs);

	static const float	aspectRatio;
	static const int32_t	gameSpaceWidth;
	static const int32_t	gameSpaceHeight;

	void	*mlx;
	void	*win;
	int32_t winWidth;
	int32_t winHeight;
	Clock	clock;
	t_input input;
	Image gameImage;
	Image winImage;
	Image *images;
	Player	P1;
    Projectile ammo[LIM_AMMO];
    int     nb_ammo;
	// NOTE(Anthony): Are you sure about the "void *mlx" being private?

	// NOTE(Nick): It's typical for most variables in a class to be private,
	//  and get/set them with functions, otherwise why not use a struct?
	// If we design this properly, you will only need to use it from within
	// the class itself
};

#endif
