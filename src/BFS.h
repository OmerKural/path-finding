#ifndef _BFS
#define _BFS

#include <SFML/Graphics.hpp>
#include "MapSquare.h"
#include "Algorithm.h"
#include <vector>
#include <queue>

using namespace std;
using namespace sf;

class BFS //:public Algorithm
{
private:
	vector<pair<int, int>> directions = {
		{-1, 0}, {0, -1}, {1, 0}, {0, 1},
		{-1, 1}, {1, -1}, {1, 1}, {-1, -1}
	};
	Vector2i startPos, target, cur;

	vector<vector<bool>> visited;
	queue<vector<Vector2i>> bfsQ;

public:
	bool finished;

	BFS(vector<vector<MapSquare*>>&, Vector2i, Vector2i);

	void step(vector<vector<MapSquare*>>&);
};

#endif // !_BFS


