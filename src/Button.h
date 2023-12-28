#ifndef BUTTON
#define BUTTON

#include <SFML/Graphics.hpp>

using namespace sf;

class Button
{
private:
	const Color fillColor = Color(210, 145, 188);
	const Color outlineColor = Color(149, 125, 173);
	IntRect buttonRect;
	RectangleShape buttonShape;

public:
	const static Vector2i size;

	Button();
	Button(Vector2i);

	bool isClicked(Mouse&, Window&);
	RectangleShape* getSprite();
};

#endif // !BUTTON


