#include <iostream>
#include "GameData.hpp"
#include "helpers.hpp"
#include <mlx.h>
#include "draw.hpp"
#include <cstdio>
#include "input.hpp"

static void	change_key_state(t_key *key, bool is_down)
{
	if (key->ended_down != is_down)
	{
		key->changed = 1;
		key->ended_down = is_down;
	}
	else
		key->changed = 0;
}

int		keyDownHook(int keycode, void *game)
{
	GameData *Game;

	Game = static_cast<GameData *>(game);
	if (keycode == K_EXIT)
		exit(0);
	if (keycode == K_UP)
		change_key_state(&Game->input.k_up, 1);
	if (keycode == K_DOWN)
		change_key_state(&Game->input.k_down, 1);
	if (keycode == K_LEFT)
		change_key_state(&Game->input.k_left, 1);
	if (keycode == K_RIGHT)
		change_key_state(&Game->input.k_right, 1);
	if (keycode == K_SPACE)
		change_key_state(&Game->input.k_space, 1);
	if (keycode == K_ENTER)
		change_key_state(&Game->input.k_enter, 1);
	return (0);
}

int		keyUpHook(int keycode, void *game)
{
	GameData *Game;

	Game = static_cast<GameData *>(game);
	if (keycode == K_EXIT)
		exit(0);
	if (keycode == K_UP)
		change_key_state(&Game->input.k_up, 0);
	if (keycode == K_DOWN)
		change_key_state(&Game->input.k_down, 0);
	if (keycode == K_LEFT)
		change_key_state(&Game->input.k_left, 0);
	if (keycode == K_RIGHT)
		change_key_state(&Game->input.k_right, 0);
	if (keycode == K_SPACE)
		change_key_state(&Game->input.k_space, 0);
	if (keycode == K_ENTER)
		change_key_state(&Game->input.k_enter, 0);
	return (0);
}

int32_t		closeHook(void *gameptr)
{
	GameData *game;
	game = static_cast<GameData *>(gameptr);
	exit (0);
}

int32_t		gameLoop(void *gameptr)
{
	GameData *game;

	game = static_cast<GameData *>(gameptr);
	game->updateTime();

//NOTE(Anthony): Upated goes 1 when any change occurs in GameData.
// After displaying the new image, upadted goes to 0

	game->P1.Player_move(&game->input);

	// if (game->updated == 1){
		mlx_clear_window(game->mlx, game->win);
		draw(game);
	// }
	// game->updated = 0;

// NOTE(nick): uncomment this to see that the game timer is working
//	std::cout << game->currentTime() << std::endl;

	return (0);
}

// NOTE(nick): GameData is a class that will hold all of our data that we pass around
// in the mlx hooks
// Still need to add functions for key hooks, and come up with C++
// way to store key and mouse input

// NOTE(nick):
// int	mlx_key_down(void *win_ptr, int (*funct_ptr)(void *), void *param);
// int	mlx_key_up(void *win_ptr, int (*funct_ptr)(void *), void *param);
// int	mlx_click_hook(void *win_ptr, int (*funct_ptr)(int, int, int, void *), void *param);
// int	mlx_mouse_moved_hook(void *win_ptr, int (*funct_ptr)(int, int, int, void *), void *param);
// int	mlx_close_hook(void *win_ptr, int (*funct_ptr)(void *), void *param);

int	main(void)
{
	GameData game = GameData("Escape EARTH", G_WIDTH, G_HEIGHT);
	game.setKeyDownHook(&keyDownHook);
	game.setKeyUpHook(&keyUpHook);
// TODO(nick): Get close hook working, right now, causes exception
// game.setCloseHook(&closeHook);
	game.setLoopHook(&gameLoop);
	game.Loop();
	return (0);
}
