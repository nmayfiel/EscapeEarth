#ifndef SKIN_HPP
# define SKIN_HPP

# include <ctime>

class Skin
{
public:
	Skin();
	~Skin();

  int x;
  int y;
  shape skin_shape;
  texture skin_texture; //set colourization on each pixel according to shape;
  colliders = check colliders on each pixel according to shape;

  void setPosition()
  void checkColliders(skin_shape);
  void drawTexture(skin_texture, Image);







};

#endif
