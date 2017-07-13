#include "GameData.hpp"

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

/*void    Player::Player_shoot(t_input *input, Projectile *ammo, int *nb_ammo)
{
    if (input->k_space.ended_down){
        Projectile::Projectile_create(ammo);
        *nb_ammo++;
    }
}*/

Player::~Player(void)
{
    return ;
}
