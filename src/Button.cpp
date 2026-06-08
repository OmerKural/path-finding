#include "Button.h"
#include <iostream>
using namespace std;

const Vector2i Button::size = Vector2i(60, 40);

Button::Button() {}

Button::Button(Vector2i position, const string& labelText, const Font& font)
{
    buttonRect = IntRect(position, size);
    buttonShape = RectangleShape();
    buttonShape.setSize(Vector2f(size));
    buttonShape.setFillColor(fillColor);
    buttonShape.setOutlineColor(outlineColor);
    buttonShape.setOutlineThickness(-2.f);
    buttonShape.setPosition(Vector2f(position));

    label.setFont(font);
    label.setString(labelText);
    label.setCharacterSize(13);
    label.setFillColor(Color(60, 30, 60));

    // center the text in the button
    FloatRect textBounds = label.getLocalBounds();
    label.setOrigin(textBounds.left + textBounds.width / 2.f,
                    textBounds.top + textBounds.height / 2.f);
    label.setPosition(position.x + size.x / 2.f, position.y + size.y / 2.f);
}

bool Button::isClicked(Mouse& mouse, Window& window)
{
    return buttonRect.contains(mouse.getPosition(window));
}

RectangleShape* Button::getSprite()
{
    return &buttonShape;
}

Text* Button::getLabel()
{
    return &label;
}