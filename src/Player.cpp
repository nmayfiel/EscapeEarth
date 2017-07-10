#include "Player.hpp"
#include "helpers.hpp"

int		Player::speed = 3;
int		Player::x = 100;
int		Player::y = 100;

Player::Player(void)
{
    return ;
}

void    Player::Player_move(int keycode)
{
    if (keycode == K_UP || keycode == K_DOWN){
        if (keycode == K_UP)
            this->y -= this->speed;
        else
            this->y += this->speed;
    }
    if (keycode == K_LEFT || keycode == K_RIGHT){
        if (keycode == K_LEFT)
            this->x -= this->speed;
        else
            this->x += this->speed;
    }
}

Player::~Player(void)
{
    return ;
}
