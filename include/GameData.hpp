#ifndef GAMEDATA_HPP
# define GAMEDATA_HPP

#include "Clock.hpp"
#include <string>

class		GameData
{
public:
	GameData(std::string winName, int32_t width, int32_t height);

	void	startLoop(void);
	void	updateTime(void);
	double	currentTime(void);
 	void	setLoopHook(int (*f)(void *));
	
private:
	void	*mlx;
	void	*win;
	Clock	clock;
};

#endif
