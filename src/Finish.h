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

	Finish(int, int);

	Color getColor();
};

#endif // FINISH

