#include "Engine.h"
#include "MapSquare.h"
#include "BFS.h"
#include "DFS.h"
#include "Mode.h"
#include "Map.h"
#include "Grid.h"
#include "Button.h"
#include "Panel.h"
#include "AStar.h"

#include <iostream>
#include <vector>
#include <random>
#include <stack>

using namespace std;
using namespace sf;

Vector2f Engine::MID = Vector2f(Engine::WIDTH / 2, Engine::HEIGHT / 2);

// Maze generation using recursive backtracker
void generateMaze(Grid& gridObj)
{
    int rows = Engine::GRID_SIZE;
    int cols = Engine::GRID_SIZE;

    // fill everything with walls
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            gridObj.updateSquare(Vector2i(i, j), 1);

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    mt19937 rng(42);

    // only carve on odd cells so walls stay between paths
    vector<pair<int,int>> dirs = {{0,2},{2,0},{0,-2},{-2,0}};

    stack<pair<int,int>> s;
    s.push({1, 1});
    visited[1][1] = true;
    gridObj.updateSquare(Vector2i(1, 1), 0);

    while (!s.empty())
    {
        auto [r, c] = s.top();
        shuffle(dirs.begin(), dirs.end(), rng);

        bool moved = false;
        for (auto [dr, dc] : dirs)
        {
            int nr = r + dr;
            int nc = c + dc;
            if (nr > 0 && nr < rows - 1 && nc > 0 && nc < cols - 1 && !visited[nr][nc])
            {
                visited[nr][nc] = true;
                // carve the wall between
                gridObj.updateSquare(Vector2i(r + dr/2, c + dc/2), 0);
                gridObj.updateSquare(Vector2i(nr, nc), 0);
                s.push({nr, nc});
                moved = true;
                break;
            }
        }
        if (!moved) s.pop();
    }
}

Engine::Engine()
{
    resolution = Vector2u(WIDTH, HEIGHT);
    window.create(VideoMode(resolution.x, resolution.y), TITLE, Style::Default);
    window.setFramerateLimit(FPS);
    event = Event();
}

void Engine::run()
{
    Mouse mouse;
    Mode mode;
    Panel panel;

    // load font
    Font font;
    font.loadFromFile("assets/arial.ttf");

    Grid gridObj(Vector2i(1, 1), Vector2i(Engine::GRID_SIZE - 3, Engine::GRID_SIZE - 3));
    generateMaze(gridObj);
	gridObj.resetStartFinish();
    vector<vector<MapSquare*>> grid = gridObj.getGrid();

    DFS dfsAlgo = DFS(grid, gridObj.getStartPos(), gridObj.getTargetPos());
    BFS bfsAlgo = BFS(grid, gridObj.getStartPos(), gridObj.getTargetPos());
    AStar astarAlgo = AStar(grid, gridObj.getStartPos(), gridObj.getTargetPos());
    bool restart = false;
    int playMode = 0;

    Button pauseButton   = panel.addButton("Pause", font);
    Button drawButton    = panel.addButton("Draw",  font);
    Button startDFSButton  = panel.addButton("DFS",  font);
    Button startBFSButton  = panel.addButton("BFS",  font);
    Button startAStarButton = panel.addButton("A*",  font);

    bool isLMBDown = false, isRMBDown = false;
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed ||
                (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape))
                window.close();

            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Right)
                isRMBDown = true;
            if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Right)
                isRMBDown = false;
            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
                isLMBDown = true;
            if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left)
            {
                isLMBDown = false;
                if (pauseButton.isClicked(mouse, window)) mode.setPause();
                if (drawButton.isClicked(mouse, window)) mode.setDraw();
                if (startDFSButton.isClicked(mouse, window))
                {
                    mode.setPlay();
                    restart = true;
                    playMode = 1;
                }
                if (startBFSButton.isClicked(mouse, window))
                {
                    mode.setPlay();
                    restart = true;
                    playMode = 2;
                }
                if (startAStarButton.isClicked(mouse, window))
                {
                    mode.setPlay();
                    restart = true;
                    playMode = 3;
                }
            }
        }

        if (mode.isDraw() && isLMBDown)
        {
            Vector2i selectedSquare = Grid::getSquareByMousePos(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
            gridObj.updateSquare(selectedSquare, 1);
            grid = gridObj.getGrid();
        }
        if (mode.isDraw() && isRMBDown)
        {
            Vector2i selectedSquare = Grid::getSquareByMousePos(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
            gridObj.updateSquare(selectedSquare, 0);
            grid = gridObj.getGrid();
        }

        if (restart)
        {
            gridObj.restartSearch();
            grid = gridObj.getGrid();

            if (playMode == 1)
                dfsAlgo = DFS(grid, gridObj.getStartPos(), gridObj.getTargetPos());
            else if (playMode == 2)
                bfsAlgo = BFS(grid, gridObj.getStartPos(), gridObj.getTargetPos());
            else if (playMode == 3)
                astarAlgo = AStar(grid, gridObj.getStartPos(), gridObj.getTargetPos());

            restart = false;
        }
        if (mode.isPlay()) {
            if (playMode == 1)
                dfsAlgo.step(grid);
            else if (playMode == 2)
                bfsAlgo.step(grid);
            else if (playMode == 3)
                astarAlgo.step(grid);
        }

        window.clear();

        for (auto &row : grid)
            for (auto &sq : row)
                window.draw(*sq->getSprite());

        window.draw(*pauseButton.getSprite());
        window.draw(*pauseButton.getLabel());
        window.draw(*drawButton.getSprite());
        window.draw(*drawButton.getLabel());
        window.draw(*startDFSButton.getSprite());
        window.draw(*startDFSButton.getLabel());
        window.draw(*startBFSButton.getSprite());
        window.draw(*startBFSButton.getLabel());
        window.draw(*startAStarButton.getSprite());
        window.draw(*startAStarButton.getLabel());

        window.display();
    }
}