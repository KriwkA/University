#include "Snake.h"


void Snake::PushBlock(int x, int y)
{
	snake.push_front({ x, y });
}

Snake_Block Snake::PopBlock()
{
	Snake_Block temp;
	temp = snake.back();
	snake.pop_back();
	return temp;
}

void Snake::DeleteSnake()
{
	snake.clear();
}

void Snake::SetDirection(Direction dir)
{
	direction = dir;
}

Snake::Direction Snake::GetDirection()
{
	return direction;
}

int Snake::GetSnakeSize()
{
	return snake.size();
}