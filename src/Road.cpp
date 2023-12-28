#include "Road.h"

const Color Road::color = Color(252, 195, 163);

Road::Road(int x, int y)
{
	this->getSprite()->setFillColor(color);
	setPos(x, y);
}

Road::Road(Vector2f position)
{
	this->getSprite()->setFillColor(color);
	setPos(position);
}

Color Road::getColor()
{
	return color;
}
