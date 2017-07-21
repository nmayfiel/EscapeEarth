#pragma once

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

	void	setImages(Image *imgs);
	void	*getMlx(void);
	void	*getWin(void);

	static const float	aspectRatio;
	static const int32_t	gameSpaceWidth;
	static const int32_t	gameSpaceHeight;

	MlxManager &mlx;
	ProjectileManager &pm;
	Clock	&clock;
	int2 winSize;
	Input input;
	Image gameImage;
	Image *images;
	Player	*P1;
};
