#include "Projectile.hpp"
#include "ProjectileManager.hpp"
// Projectiles need :
// velocity in meters per second
// is_alive
// x
// y
// texture_id
// collision mask
// damage_value


ProjectileManager::ProjectileManager(void): count(0), lastIndex(0){}

void	ProjectileManager::update(double dt)
{
	for (uint32_t i = 0; i < count; i++)
		projectiles[i].update(dt);
}

void	ProjectileManager::add(float2 position)
{
	if (lastIndex < MAX_AMMO && count < MAX_AMMO)
	{
		projectiles[lastIndex].setValues(position, 800, true);
		++lastIndex;
		++count;
	}
	else
		return ;
	//if (count != 0)
	
}

void	ProjectileManager::killAtIndex(int index)
{
	// on bullet 0, the count should be one.
	// on bullet 1, the count should be two.
	if (index != MAX_AMMO - 1)
	{
		projectiles[index].position = projectiles[count - 1].position;
		projectiles[index].velocity = projectiles[count - 1].velocity;
	}
	projectiles[count - 1].kill();
	lastIndex--;
	count--;
}
