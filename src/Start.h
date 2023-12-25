#ifndef START
#define START

#include <SFML/Graphics.hpp>
#include "MapSquare.h"

using namespace std;
using namespace sf;

class Start :public MapSquare
{
private:

public:
	static const Color color;

	Start(int, int);

	Color getColor();
};

#endif // START

