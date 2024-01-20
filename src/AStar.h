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
	bool operator()(const pair<int, Vector2i>& top, const pair<int, Vector2i>& bot) const {
		return top.first > bot.first;
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

	vector<vector<int>> gScore, fScore;
	vector<vector<Vector2i>> cameFrom;
	vector<vector<bool>> visited;
	priority_queue<pair<int, Vector2i>, vector<pair<int, Vector2i>>, Compare> astarQ;

public:
	bool finished;

	AStar(vector<vector<MapSquare*>>&, Vector2i, Vector2i);

	void step(vector<vector<MapSquare*>>&);
};


#endif ASTAR
