#include "GameData.hpp"

Projectile::Projectile(void)
{
    return ;
}

//void        Projectile_move(Projectile *ammo)

void        Projectile::Projectile_move(GameData *game)
{
    Projectile      *bullets;

    bullets = static_cast<Projectile *>(game->ammo);
//NOTE(Anthony): This loop go through all enemies. If the id is negative
//the bullet goes up, if not the bullet go down.

        for(int i = 0; i < game->nb_ammo; i++)
            if (bullets[i].is_alive)
                bullets[i].y += (bullets[i].id > 0 ? bullets[i].speed : -bullets[i].speed);
}

void        Projectile::Projectile_create(GameData *game)
{
    Projectile      *bullets;
    Player          *player;

    bullets = static_cast<Projectile *>(game->ammo);
    player = static_cast<Player *>(game->P1);
    game->nb_ammo++;
    bullets[game->nb_ammo].x = player->x;
    bullets[game->nb_ammo].y = player->y;
    bullets[game->nb_ammo].velocity = player->velocity;
    bullets[game->nb_ammo].damage = player->damage;
    //ammo.tx_index = tx_index;
    bullets[game->nb_ammo].is_alive = 1;
    bullets[game->nb_ammo].id = player->id;
}

Projectile::~Projectile(void)
{
    return ;
}
