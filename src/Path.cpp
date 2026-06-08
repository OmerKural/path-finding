
#include "Path.h"

const Color Path::color = Color(99, 43, 108);


Path::Path(int x, int y)
{
	this->getSprite()->setFillColor(color);
	setPos(x, y);
}

Color Path::getColor()
{
	return color;
}