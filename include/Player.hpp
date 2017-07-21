#pragma once

# include <iostream>
# include <ctime>
# include "input.hpp"
# include "vec.hpp"

class Player
{
public:
	Player(float2 position);

	float2			position;
	float			angle;
	float2			velocity;

	void	move(float3 direction, double dt);
	
};
