#include "Start.h"

const Color Start::color = Color(39, 15, 54);

Start::Start(int x, int y)
{
	this->getSprite()->setFillColor(color);
	setPos(x, y);
}

Color Start::getColor()
{
	return color;
}