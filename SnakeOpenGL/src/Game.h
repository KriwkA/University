#pragma once

#include "Map.h"
#include "Painter.h"
#include "Snake.h"

enum State{ GAME, PAUSE };

class Game
{
private:
	Snake snake;
	Painter painter;
	Map map;
	const int heigh;
	const int width;
	const int size;
	int X;
	int Y;
	int level;
	int speed;
	State state;
public:
	Game();
	void drow();
	void NewGame();
	void NewFruit();
	int tick();
	int GetSpeed();

	enum Key{ UP, DOWN, LEFT, RIGHT, PAUSE};
	void keyEvent(Key);
};

