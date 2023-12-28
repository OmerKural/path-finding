#ifndef _DFS
#define _DFS

#include <SFML/Graphics.hpp>
#include "MapSquare.h"
#include "Algorithm.h"
#include <vector>
#include <stack>

using namespace std;
using namespace sf;

class DFS //:public Algorithm
{
private:
	vector<pair<int, int>> directions = {
		{-1, 0}, {0, -1}, {1, 0}, {0, 1}
	};
	Vector2i dimensions, startPos, targetPos, cur;

	vector<vector<bool>> visited;
	stack<vector<Vector2i>> dfsS;

public:
	bool finished;

	DFS(vector<vector<MapSquare*>>&, Vector2i, Vector2i);

	void step(vector<vector<MapSquare*>>&);
};

#endif // !_DFS


