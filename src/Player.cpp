#include "Player.hpp"
#include "helpers.hpp"

Player::Player(float2 position): position(position), velocity(0.0, 0.0) {}

void    Player::move(float3 direction, double dt)
{
	if (direction.x == 1)
		position.x += 200.0 * dt;
	if (direction.y == 1)
		position.y += 200.0 * dt;
	if (direction.x == -1)
		position.x -= 200.0 * dt;
	if (direction.y == -1)
		position.y -= 200.0 * dt;
}
