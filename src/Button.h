#ifndef BUTTON
#define BUTTON

#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
using namespace std;

class Button
{
private:
    const Color fillColor = Color(210, 145, 188);
    const Color outlineColor = Color(149, 125, 173);
    IntRect buttonRect;
    RectangleShape buttonShape;
    Text label;

public:
    const static Vector2i size;

    Button();
    Button(Vector2i position, const string& labelText, const Font& font);

    bool isClicked(Mouse&, Window&);
    RectangleShape* getSprite();
    Text* getLabel();
};

#endif