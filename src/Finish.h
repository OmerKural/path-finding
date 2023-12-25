#ifndef FINISH
#define FINISH

#include <SFML/Graphics.hpp>
#include "MapSquare.h"

using namespace std;
using namespace sf;

class Finish:public MapSquare
{
private:

public:
	static const Color color;

	Finish();

	Color getColor();
};

#endif // FINISH

