#include <iostream>
#include "GameData.hpp"

int32_t		gameLoop(void *gameptr)
{
	GameData *game;

	game = static_cast<GameData *>(gameptr);
	game->updateTime();

// NOTE(nick): uncomment this to see that the game timer is working
//	std::cout << game->currentTime() << std::endl;

	return (0);
}

// NOTE(nick): GameData is a class that will hold all of our data that we pass around
// in the mlx hooks
// Still need to add functions for key hooks, and come up with C++
// way to store key and mouse input

int	main(void)
{
	GameData game = GameData("Escape EARTH", 768, 768);

	game.setLoopHook(&gameLoop);
	game.startLoop();
	return (0);
}
