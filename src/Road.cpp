#include "Road.h"

const Color Road::color = Color(252, 195, 163);

Road::Road()
{
	this->getSprite()->setFillColor(color);
}

Color Road::getColor()
{
	return color;
}
