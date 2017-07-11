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
  shape shape;
  texture texture; //set colourization on each pixel according to shape;

  void setPosition()
  void checkColliders(); //check colliders on each pixel according to shape;
  void applyTexture(Image);







};

#endif
