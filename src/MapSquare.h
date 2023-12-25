#ifndef MAPSQUARE
#define MAPSQUARE

#include <SFML/Graphics.hpp>

using namespace sf;

/// <summary>
/// 0 -> road
/// 1 -> wall
/// 2 -> start
/// 3 -> target
/// </summary>

class MapSquare
{
private:
	static const int size;
	Vector2f position;
	RectangleShape shape;

public:
	MapSquare();

	static int getSize();
	Vector2f getPos();
	void setPos(Vector2f new_position);
	RectangleShape* getSprite();
	virtual Color getColor();
};


#endif // !MAPSQUARE