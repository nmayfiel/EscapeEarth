#ifndef PLAYER_CLASS_HPP
# define PLAYER_CLASS_HPP

# include <iostream>
# include <ctime>

class Player : public AObject
{
public:
	Player(Game &g);
	~Player();

	bool						getDoesMove() const;
	bool						getDoesShoot() const;

	// void						moveCall(Game const &g);
	void						moveEvent(Game const &g, int x, int y);

	int							getPosX(void) const;
	int							getPosY(void) const;
	void						setPosX(int x);
	void						setPosY(int y);
	void						setPosXY(int x, int y);
	void  setDeleteObject(bool b);
	Game						&getGame(void);

protected:
private:
	// Player						&operator=(Player const &rhs);
	Player();
	Player(Player const &src);

	Game						&_game;
	// static std::string const	_mobName;
	static Shape const		  _mobShape;
	static bool const		   _doesMove;
	static bool const		   _doesShoot;
};
//std::ostream					&operator<<(std::ostream &o, Player const &rhs);

#endif
