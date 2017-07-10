#include "Player.hpp"

Player::Player(void)
{
    return ;
}

Player::Player_move(int keycode)
{
    if (keycode == K_UP || keycode == K_DOWN){
        if (keycode == K_UP)
            this.y -= this.speed;
        else
            this.y += this.speed;
    }
    if (keycode == K_LEFT || keycode == K_RIGHT){
        if (keycode == k_LEFT)
            this.x -= this.speed;
        else
            this.y +- this.speed;
    }
}

Player::~Player(void)
{
    return ;
}
