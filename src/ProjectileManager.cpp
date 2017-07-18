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


ProjectileManager::ProjectileManager(void): count(0), currentIndex(0){}

void	ProjectileManager::update(double dt)
{
	
}

void	ProjectileManager::add(float x, float y, )
{
	if (lastIndex < 999 && count <= 999)
		projectiles[lastIndex].setValues(x, y, 0, 20, 1, texture_index);
	else
		return ;
	if (count != 0)
		++lastIndex;
	++count;
}

void	ProjectileManager::remove(void)
{
	
}
