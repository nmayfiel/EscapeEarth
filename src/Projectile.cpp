#include "GameData.hpp"

Projectile::Projectile(void)
{
    return ;
}

//void        Projectile_move(Projectile *ammo)
void        Projectile_move(GameData *game)
{
//NOTE(Anthony): This loop go through all enemies. If the id is negative
//the bullet goes up, if not the bullet go down.

        for(int i = 0; i < game->nb_ammo; i++)
            if (game->ammo[i].is_alive)
                game->ammo[i].y += (game->ammo[i].id > 0 ? game->ammo[i].speed : -game->ammo[i].speed);
}

void        Projectile_create(GameData *game)
{
    game->ammo[game->nb_ammo].x = game->P1.x;
    game->ammo[game->nb_ammo].y = game->P1.y;
    game->ammo[game->nb_ammo].velocity = game->P1.velocity;
    game->ammo[game->nb_ammo].damage = game->P1.damage;
    //ammo.tx_index = tx_index;
    game->ammo[game->nb_ammo].is_alive = 1;
    game->ammo[game->nb_ammo].id = game->P1.id;
}

Projectile::~Projectile(void)
{
    return ;
}
