#ifndef ASTAR
#define ASTAR

#include <SFML/Graphics.hpp>
#include "MapSquare.h"
#include "Algorithm.h"
#include <vector>
#include <queue>

using namespace std;
using namespace sf;

struct Compare {
	bool operator()(const pair<Vector2i, vector<Vector2i>>& top, const pair<Vector2i, vector<Vector2i>>& bot) const {
		return top.first.x + top.first.y > bot.first.x + bot.first.y;
	}
};

class AStar
{
private:
	vector<pair<int, int>> directions = {
		{-1, 0}, {0, -1}, {1, 0}, {0, 1},
		{-1, 1}, {1, -1}, {1, 1}, {-1, -1}
	};
	Vector2i startPos, targetPos, curPos;

	vector<vector<bool>> visited;
	priority_queue<pair<Vector2i, vector<Vector2i>>, vector<pair<Vector2i, vector<Vector2i>>>, Compare> astarQ;

public:
	bool finished;

	AStar(vector<vector<MapSquare*>>&, Vector2i, Vector2i);

	void step(vector<vector<MapSquare*>>&);
};


#endif ASTAR
