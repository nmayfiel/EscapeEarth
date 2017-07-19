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
	if (lastIndex < 999 && count <= 999)
	{
		projectiles[lastIndex].setValues(position, 20, true);
		++lastIndex;
		++count;
	}
	else
		return ;
	//if (count != 0)
	
}

void	ProjectileManager::killAtIndex(int index)
{
	projectiles[index] = projectiles[lastIndex];
	projectiles[lastIndex].kill();
	lastIndex--;
	count--;
}
