#include "Projectile.hpp"

Projectile::Projectile(void): position(0.0, 0.0), velocity(0.0), isAlive(0){}

void	Projectile::kill(void)
{
	isAlive = false;
}

void	Projectile::update(double dt)
{
	position.y -= velocity * dt;
}

void	Projectile::setValues(float2 position, float velocity, bool isAlive)
{
	this->position = position;
	this->velocity = velocity;
	this->isAlive = isAlive;
}
