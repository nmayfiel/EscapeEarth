#include "Player.hpp"
#include "helpers.hpp"

int		Player::speed = 3;
int		Player::x = 100;
int		Player::y = 100;

Player::Player(void)
{
    return ;
}

void    Player::Player_move(t_input *input)
{
	if (input->k_up.ended_down)
		this->y -= this->speed;
	if (input->k_down.ended_down)
		this->y += this->speed;
	if (input->k_left.ended_down)
		this->x -= this->speed;
	if (input->k_right.ended_down)
		this->x += this->speed;
}

Player::~Player(void)
{
    return ;
}
