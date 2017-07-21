#include "Projectile.hpp"
#include "ProjectileManager.hpp"

ProjectileManager::ProjectileManager(void): count(0) {}

void	ProjectileManager::update(double dt)
{
	for (uint32_t i = 0; i < count; ++i)
		projectiles[i].update(dt);
}

void	ProjectileManager::add(float2 position)
{
	if (count < MAX_AMMO)
	{
		projectiles[count].setValues(position, 800, true);
		++count;
	}
}

void	ProjectileManager::killAtIndex(int index)
{
	if (index != MAX_AMMO - 1)
	{
		projectiles[index].position = projectiles[count - 1].position;
		projectiles[index].velocity = projectiles[count - 1].velocity;
	}
	projectiles[count - 1].kill();
	count--;
}
