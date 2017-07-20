#pragma once

#include "vec.hpp"

class Projectile
{
public:
	Projectile(void);

	float2	position;
	float	velocity;
	bool	isAlive;
	void	kill(void);
	void	update(double dt);
	void	setValues(float2 position, float velocity, bool isAlive);
};
