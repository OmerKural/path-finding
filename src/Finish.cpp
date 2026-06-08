#include "Finish.h"

const Color Finish::color = Color(39, 15, 54);

Finish::Finish(int x, int y)
{
	this->getSprite()->setFillColor(color);
	setPos(x, y);
}

Color Finish::getColor()
{
	return color;
}
