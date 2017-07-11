#include "skin.hpp"
#include "Player.hpp"
#include "helpers.hpp"


Skin::Skin(void)
{
  this->x = Player::x;
  this->y = Player::y;
  return ;
}

Skin::setPosition(void)
{
  this->x = Player::x;
  this->y = Player::y;
  return ;
}

Skin::checkColliders(shape){
  while (shape is still giving x,y coordinate offsets)
    if (given coordinate is shared by a object::type->hostile_object)
      receive damage from object;
}

Skin::drawTexture(shape){
  while (shape is still giving x,y coordinate offsets)
    append-to-image(given coordinate of skin's texture pack);
}


Skin::~Skin(void)
{
  return ;
}
