#ifndef PROJECTILE_MANAGER_HPP
# define PROJECTILE_MANAGER_HPP

#include "Projectile.hpp"

class	ProjectileManager
{
public:
	ProjectileManager(void);

	void	update(double dt);
	void	add(void);
	void	remove(void);

	Projectile	projectiles[1000];
	uint32_t	count;
	uint32_t	lastIndex;
	
};

#endif
