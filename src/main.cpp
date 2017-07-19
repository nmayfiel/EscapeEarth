#include <iostream>
#include <mlx.h>
#include <cstdio>
#include "GameData.hpp"
#include "helpers.hpp"
#include "draw.hpp"
#include "input.hpp"
#include "image.hpp"
#include "MlxManager.hpp"
#include "ProjectileManager.hpp"

extern const uint8_t image_one_start;
extern const int32_t image_one_size;
extern const uint8_t image_two_start;
extern const int32_t image_two_size;
extern const uint8_t image_three_start;
extern const int32_t image_three_size;

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

int		keyDownHook(int keycode, void *in)
{
	t_input *input;

	input = static_cast<t_input *>(in);
	if (keycode == K_EXIT)
		exit(0);
	if (keycode == K_UP)
		change_key_state(&input->k_up, 1);
	if (keycode == K_DOWN)
		change_key_state(&input->k_down, 1);
	if (keycode == K_LEFT)
		change_key_state(&input->k_left, 1);
	if (keycode == K_RIGHT)
		change_key_state(&input->k_right, 1);
	if (keycode == K_SPACE)
		change_key_state(&input->k_space, 1);
	if (keycode == K_ENTER)
		change_key_state(&input->k_enter, 1);
	return (0);
}

int		keyUpHook(int keycode, void *in)
{
	t_input *input;

	input = static_cast<t_input *>(in);
	if (keycode == K_EXIT)
		exit(0);
	if (keycode == K_UP)
		change_key_state(&input->k_up, 0);
	if (keycode == K_DOWN)
		change_key_state(&input->k_down, 0);
	if (keycode == K_LEFT)
		change_key_state(&input->k_left, 0);
	if (keycode == K_RIGHT)
		change_key_state(&input->k_right, 0);
	if (keycode == K_SPACE)
		change_key_state(&input->k_space, 0);
	if (keycode == K_ENTER)
		change_key_state(&input->k_enter, 0);
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
	if (game->input.k_space.ended_down)
	{
		float2 position = float2(game->P1.x, game->P1.y);
		game->pm.add(position);
	}
	game->pm.update(game->clock.lastFrameTime);
	// if (game->updated == 1){
//	mlx_clear_window(game->mlx, game->win);
	draw(game);
	//draw(game);
	// }
	// game->updated = 0;

	return (0);
}

int32_t		resizeHook(int width, int height, void *gameptr)
{
	GameData *game;

	float xscale, yscale;
	game = static_cast<GameData *>(gameptr);
	game->winSize.x = width;
	game->winSize.y = height;
	float w, h;
	w = width;
	h = height;

	if (h / w > game->aspectRatio)
	{
		xscale = 1.0 / ((float)game->gameSpaceWidth / w);
		yscale = xscale;
	}
	else
	{
		yscale = 1.0 / ((float)game->gameSpaceHeight / h);
		xscale = yscale;
	}

	game->gameImage.scale = float2(xscale, yscale);
	game->gameImage.center.x = ((float)game->gameImage.width  * xscale) / 2;
	game->gameImage.center.y = ((float)game->gameImage.height * yscale) / 2;
	//std::cout << "x" << width << std::endl;
	//std::cout << "y" << height << std::endl;
	return (0);
}

int	main(void)
{
	MlxManager mlx;
	Clock clock;
	ProjectileManager projectiles;
	int2 size = int2(G_WIDTH, G_HEIGHT);

	mlx.init();
	mlx.newWindow(G_WIDTH, G_HEIGHT, "Escape EARTH");
	GameData game = GameData(mlx, projectiles, clock, size);
//	GameData game = GameData(mlx.getMlx(), mlx.getWin(), clock, G_WIDTH, G_HEIGHT);

	// TODO(nick): These images probably need to be std::vector
	// 	maybe try to mess with images.asm to get them in a better format
	// 	you may only need a pointer to the start, then a number for sizes
	//	of each, then maybe an end, for a sanity check ?
	Image *images = new Image[3];
	images[0].getImageFromData(mlx.getMlx(), &image_one_start, image_one_size);
	images[1].getImageFromData(mlx.getMlx(), &image_two_start, image_two_size);
	images[2].getImageFromData(mlx.getMlx(), &image_three_start, image_three_size);
	game.setImages(images);

	mlx.setKeyDownHook(&keyDownHook, &game.input);
	mlx.setKeyUpHook(&keyUpHook, &game.input);
	mlx.setLoopHook(&gameLoop, &game);
	mlx.setCloseHook(&closeHook, &game);
	mlx.setResizeHook(&resizeHook, &game);
	mlx.startLoop();
	return (0);
}
