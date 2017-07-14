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

	GameData(void*& mlx, void*& win, Clock &c, int32_t width, int32_t height);

	void	updateTime(void);
	double	currentTime(void);
	void	setImages(Image *imgs);
	void	setWidthHeight(int w, int h);
	void	*mlx(void);
	void	*win(void);

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
	
	// NOTE(Anthony): Are you sure about the "void *mlx" being private?
	// NOTE(Nick): Yes, it should be private eventually, this is typical
	// 	when you want to control who can set it. We will only set it
	//	one time, then after that we will just get it with the member
	//	function void *mlx()
};

#endif
