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

	// MARK(nick): update the time
	game->clock.tick();
	double dt = game->clock.lastFrameDuration;

	// MARK(nick): change the player direction
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

	// MARK(nick): fire some bullets
	float2 playerPosition = float2(game->P1->position.x, game->P1->position.y);
	if (game->input.space.endedDown)
		game->pm.add(playerPosition);
	game->pm.update(dt);

	// MARK(nick): do the bullet collision
	for (uint32_t i = 0; i < game->pm.count; i++)
	{
		bool swap;
		Projectile bullet;
		do {
			bullet = game->pm.projectiles[i];
			swap = false;
			if (bullet.isAlive
			    && (bullet.position.x < 0
				|| bullet.position.x > game->gameImage.width
				|| bullet.position.y < 0
				|| bullet.position.y > game->gameImage.height))
			{
				swap = true;
				game->pm.killAtIndex(i);
			}
		} while (swap);
	}

	draw(game);

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
	mlx.startLoop();
	return (0);
}
