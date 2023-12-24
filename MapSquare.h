#ifndef MAPSQUARE
#define MAPSQUARE

#include <SFML/Graphics.hpp>

using namespace sf;

/**
* 1 -> Road 
* 2 -> Wall -> toggle drawing mode with 'W'
* 

*/

class MapSquare
{
private:

	RectangleShape shape;
	Vector2f position;
	Color color;

public:
	static const int size;

	MapSquare();

	int getSize();
	Vector2f getPos();
	RectangleShape getSprite();
	Color getColor();
	void setPos(Vector2f new_position);
	void setColor(Color new_color);

};


#endif // !MAPSQUARE