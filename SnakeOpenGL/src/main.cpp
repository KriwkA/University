#include <GL/glut.h>
#include <iostream>

#include "Game.h"

#define max(a,b) (((a)>(b))?(a):(b));
#define min(a,b) (((a)<(b))?(a):(b));

#define WIN_WIDTH 600
#define WIN_HEIGH 400
#define BLOCK_SIZE 20

Game game;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	game.drow();
	glFlush();
}

void keyEvent(int key, int, int)
{
	switch (key)
	{
	case    GLUT_KEY_UP: game.keyEvent(Game::UP);  break;
	case  GLUT_KEY_DOWN: game.keyEvent(Game::DOWN); break;
	case  GLUT_KEY_LEFT: game.keyEvent(Game::LEFT);  break;
	case GLUT_KEY_RIGHT: game.keyEvent(Game::RIGHT); break;
	case GLUT_KEY_F1: game.keyEvent(Game::PAUSE); break;
	}
}

void timer(int)
{
	if(game.tick()==1)game.NewGame();
	display();
	glutTimerFunc(150-game.GetSpeed(), timer, 0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(WIN_WIDTH, WIN_HEIGH);
	glutCreateWindow("Snake");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, WIN_WIDTH, 0, WIN_HEIGH, -1.0, 1.0);
	glutDisplayFunc(display);
	glutSpecialFunc(keyEvent);
	glutTimerFunc(150 - game.GetSpeed(), timer, 0);

	glutMainLoop();
    return 0;
}
