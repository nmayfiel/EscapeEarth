#ifndef PLAYER_HPP
# define PLAYER_HPP

# include <iostream>
# include <ctime>

class Player
{
public:
	Player();
	~Player();

  static int		x;
  static int		y;
	static int		speed;
	Skin		skin;

	void	Player_move(int keycode);

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
