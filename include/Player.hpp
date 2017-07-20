#ifndef PLAYER_HPP
# define PLAYER_HPP

# include <iostream>
# include <ctime>
# include "input.hpp"
# include "vec.hpp"

class Player
{
public:
	Player(float2 position);

	float2			position;
	//static int		x;
	//static int		y;
	float			angle;
	float2			velocity;
//	static int		speed;
//	Skin		skin;
	
	void	move(float3 direction, double dt);
	
	// //bool	getDoesMove() const;
	// //bool	getDoesShoot() const;
	//
	// // void						moveCall(Game const &g);
	// void 	moveEvent(Game const &g, int x, int y);
	//
	// int		getPosX(void) const;
	// int		getPosY(void) const;
	// void 	setPosX(int x);
	// void 	setPosY(int y);
	// void 	setPosXY(int x, int y);
	// void 	setDeleteObject(bool b);
	// Game	&getGame(void);
};
//std::ostream					&operator<<(std::ostream &o, Player const &rhs);

#endif
