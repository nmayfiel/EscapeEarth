#ifndef PROJECTILE_HPP
# define PROJECTILE_HPP

//  class Player;
class GameData;

class Projectile
{
    public:
    Projectile();
    ~Projectile();

    float   x;
    float   y;
    float   speed;
    int     id;
    float   velocity;
    bool    is_alive;
    int     damage;

    //Texture tx[]
    //int   tx_index;
    void        Projectile_move(GameData *game);
    void        Projectile_set(GameData *game, int i, int state, int id_src);
};

#endif
