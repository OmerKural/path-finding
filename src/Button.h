#ifndef BUTTON
#define BUTTON

#include <SFML/Graphics.hpp>

using namespace sf;

class Button
{
private:
	const Color fillColor = Color(210, 145, 188);
	const Color outlineColor = Color(149, 125, 173);
	const Vector2i size = Vector2i(40, 40);
	Vector2i position;
	IntRect buttonRect;
	RectangleShape buttonShape;

public:
	Button(Vector2i);

	bool isClicked(Mouse&, Window&);
	RectangleShape* getSprite();
};

#endif // !BUTTON


