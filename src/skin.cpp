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

Skin::checkColliders(){
  while (this->shape is still giving x,y coordinate offsets)
    if (Image::this_coordinate(x,y)->object->type != this_skins->object->type){
      object::this->hp - object::existing->damage;
      object::existing-> hp - object::this->damage;
    }
}


Skin::applyTexture(Image){
  while (this->shape is still giving x,y coordinate offsets)
    append-to-image(this->shape->x, this->shape->y, this->texture);
}


Skin::~Skin(void)
{
  return ;
}
