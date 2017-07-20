#ifndef PROJECTILE_MANAGER_HPP
# define PROJECTILE_MANAGER_HPP

#include <string>
#include "Projectile.hpp"

# define MAX_AMMO 100

class	ProjectileManager
{
public:
	ProjectileManager(void);

	void	update(double dt);
	void	add(float2 position);
	void	killAtIndex(int index);

	Projectile	projectiles[MAX_AMMO];
	uint32_t	count;
	uint32_t	lastIndex;	
};

#endif
