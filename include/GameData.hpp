#ifndef GAMEDATA_HPP
# define GAMEDATA_HPP

#include "vec.hpp"
#include "Clock.hpp"
#include "Player.hpp"
#include "input.hpp"
#include "image.hpp"
#include "MlxManager.hpp"
#include "ProjectileManager.hpp"
#include <string>

class		GameData
{
public:
	GameData(MlxManager &mlx, ProjectileManager &p, Clock &c, int2 &size);

	void	updateTime(void);
	double	currentTime(void);
	void	setImages(Image *imgs);
	void	*getMlx(void);
	void	*getWin(void);

	static const float	aspectRatio;
	static const int32_t	gameSpaceWidth;
	static const int32_t	gameSpaceHeight;

	MlxManager &mlx;
	ProjectileManager &pm;
	Clock	&clock;
	vec2<int32_t> winSize;
//	int32_t winWidth;
//	int32_t winHeight;
	t_input input;
	Image gameImage;
	Image *images;
	Player	P1;
	
	// NOTE(Anthony): Are you sure about the "void *mlx" being private?
	// NOTE(Nick): Yes, it should be private eventually, this is typical
	// 	when you want to control who can set it. We will only set it
	//	one time, then after that we will just get it with the member
	//	function void *mlx()
};

#endif
