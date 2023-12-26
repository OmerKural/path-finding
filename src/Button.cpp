#include "Button.h"
#include <iostream>
using namespace std;

Button::Button(Vector2i position)
{
	this->position = position;
	buttonRect = IntRect(position, size);
	buttonShape = RectangleShape();
	buttonShape.setSize(Vector2f(size));
	buttonShape.setFillColor(fillColor);
	buttonShape.setOutlineColor(outlineColor);
	buttonShape.setOutlineThickness(-2.f);
	buttonShape.setPosition(Vector2f(position));
}

bool Button::isClicked(Mouse &mouse, Window &window)
{
	return buttonRect.contains(mouse.getPosition(window));
}

RectangleShape* Button::getSprite()
{
	return &buttonShape;
}