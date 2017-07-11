#include "Player.hpp"
#include "helpers.hpp"

int		Player::speed = 3;
int		Player::x = 100;
int		Player::y = 100;

Player::Player(void)
{
    return ;
}

void    Player::Player_move(t_input input)
{
    if (input->k_up || input->k_down){
        if (input->k_up)
            this->y -= this->speed;
        else
            this->y += this->speed;
    }
    if (input->k_left || input->k_right){
        if (input->k_left)
            this->x -= this->speed;
        else
            this->x += this->speed;
    }
}

Player::~Player(void)
{
    return ;
}
