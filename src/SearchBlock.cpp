#include "SearchBlock.h"

const Color SearchBlock::color = Color(240, 159, 156);


SearchBlock::SearchBlock(int x, int y)
{
	this->getSprite()->setFillColor(color);
	setPos(x, y);
}

Color SearchBlock::getColor()
{
	return color;
}