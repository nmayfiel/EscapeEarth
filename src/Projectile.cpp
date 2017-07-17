#include "GameData.hpp"

Projectile::Projectile(void)
{
    this->x = 0;
    this->y = 0;
    this->velocity = 0;
    this->damage = 20;
    this->is_alive = 0;
    this->id = 0;
    return ;
}

//void        Projectile_move(Projectile *ammo)

void        Projectile::Projectile_move(GameData *game)
{
    Projectile      *bullets;
    Player          *player;

    bullets = static_cast<Projectile *>(game->ammo);
    player = static_cast<Player *>(game->P1);
//NOTE(Anthony): This loop go through all enemies. If the id is negative
//the bullet goes up, if not the bullet go down.

        for(int i = 0; i < game->nb_ammo; i++){
            if (bullets[i].is_alive)
                bullets[i].y -= (bullets[i].id > 0 ? -bullets[i].velocity : bullets[i].velocity);
            std::cout << i << "--- Moving Projectiles ---" << std::endl;
            std::cout << player->x << " " << bullets[i].x << std::endl;
            std::cout << player->y << " " << bullets[i].y << std::endl;

        }
}

void        Projectile::Projectile_set(GameData *game, int i)
{
    Projectile      *bullets;
    Player          *player;

    bullets = static_cast<Projectile *>(game->ammo);
    player = static_cast<Player *>(game->P1);
    bullets[i].x = player->x;
    bullets[i].y = player->y;
    bullets[i].velocity = 3.0f;
    bullets[i].damage = player->damage;
    //ammo.tx_index = tx_index;
    bullets[i].is_alive = 1;
    bullets[i].id = player->id;
}

Projectile::~Projectile(void)
{
    return ;
}
