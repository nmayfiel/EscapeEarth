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

static void	change_key_state(Key *key, bool is_down)
{
	if (key->endedDown != is_down)
	{
		key->changed = 1;
		key->endedDown = is_down;
	}
	else
		key->changed = 0;
}

int		keyDownHook(int keycode, void *in)
{
	Input *input;

	input = static_cast<Input *>(in);
	if (keycode == K_EXIT)
		exit(0);
	if (keycode == K_UP)
		change_key_state(&input->up, 1);
	if (keycode == K_DOWN)
		change_key_state(&input->down, 1);
	if (keycode == K_LEFT)
		change_key_state(&input->left, 1);
	if (keycode == K_RIGHT)
		change_key_state(&input->right, 1);
	if (keycode == K_SPACE)
		change_key_state(&input->space, 1);
	if (keycode == K_ENTER)
		change_key_state(&input->enter, 1);
	return (0);
}

int		keyUpHook(int keycode, void *in)
{
	Input *input;

	input = static_cast<Input *>(in);
	if (keycode == K_EXIT)
		exit(0);
	if (keycode == K_UP)
		change_key_state(&input->up, 0);
	if (keycode == K_DOWN)
		change_key_state(&input->down, 0);
	if (keycode == K_LEFT)
		change_key_state(&input->left, 0);
	if (keycode == K_RIGHT)
		change_key_state(&input->right, 0);
	if (keycode == K_SPACE)
		change_key_state(&input->space, 0);
	if (keycode == K_ENTER)
		change_key_state(&input->enter, 0);
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
	double dt = game->clock.lastFrameTime;

//NOTE(Anthony): Upated goes 1 when any change occurs in GameData.
// After displaying the new image, upadted goes to 0

	float3 direction;
	if (game->input.down.endedDown)
		direction.y = 1;
	if (game->input.up.endedDown)
		direction.y = -1;
	if (game->input.left.endedDown)
		direction.x = -1;
	if (game->input.right.endedDown)
		direction.x = 1;
	if(game->input.down.endedDown && game->input.up.endedDown)
		direction.y = 0;
	if (game->input.right.endedDown && game->input.left.endedDown)
		direction.x = 0;
	game->P1->move(direction, dt);

	float2 playerPosition = float2(game->P1->position.x, game->P1->position.y);
	if (game->input.space.endedDown)
		game->pm.add(playerPosition);
	game->pm.update(dt);

	draw(game);
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
