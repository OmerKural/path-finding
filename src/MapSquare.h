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
	Vector2f position;
	RectangleShape shape;

public:
	static const int size;
	
	MapSquare();

	Vector2f getPos();
	void setPos(int, int);
	void setPos(Vector2f);
	RectangleShape* getSprite();
	virtual Color getColor();
};


#endif // !MAPSQUARE