#pragma once
#include <list>

typedef std::pair<int, int> Snake_Block;

class Snake
{
public:
	enum Direction{ UP, DOWN, LEFT, RIGHT };
	void PushBlock(int,int);
	Snake_Block PopBlock();
	void SetDirection(Direction);
	void DeleteSnake();
	Direction GetDirection();
	int GetSnakeSize();
private:
	std::list<Snake_Block> snake;
	Direction direction;
};

