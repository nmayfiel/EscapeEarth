#include <iostream>
#include "GameData.hpp"
#include "helpers.hpp"
#include <mlx.h>
#include "draw.hpp"
#include <cstdio>

int		key_press_hook(int keycode, GameData *Game)
{
	if (keycode == K_EXIT){
		exit(0);
	}
	if (keycode >= K_LEFT && keycode <= K_UP) {
		Game->P1.Player_move(keycode);
		Game->updated = 1;
	}
	if (keycode == K_SPACE) {
		//Game->P1.Player_shoot(keycode);
		Game->updated = 1;
	}
	return (0);
}

int32_t		gameLoop(void *gameptr)
{
	GameData *game;

	game = static_cast<GameData *>(gameptr);
	game->updateTime();

//NOTE(Anthony): Upated goes 1 when any change occurs in GameData.
// After displaying the new image, upadted goes to 0
	if (game->updated == 1){
		mlx_clear_window(game->mlx, game->win);
		draw(game);
	}
	game->updated = 0;

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
	GameData game = GameData("Escape EARTH", G_WIDTH, G_HEIGHT);
	game.updated = 1;
	game.SetKeyHook(&key_press_hook);
	game.setLoopHook(&gameLoop);
	game.Loop();
	return (0);
}
