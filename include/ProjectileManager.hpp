#pragma once

#include <string>
#include "Projectile.hpp"

# define MAX_AMMO 100

// Note(nick): Projectiles need :
// texture_id
// collision mask
// damage_value


class	ProjectileManager
{
public:
	ProjectileManager(void);

	void	update(double dt);
	void	add(float2 position);
	void	killAtIndex(int index);

	Projectile	projectiles[MAX_AMMO];
	uint32_t	count;
};
