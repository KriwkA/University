#include "Painter.h"
#include <GL/glut.h>
#include <cmath>

#define PI 3.1415926


void Painter::drowRect(double x1, double y1, double x2, double y2)
{
	glBegin(GL_QUADS);
	glVertex2d(x1, y1);
	glVertex2d(x1, y2);
	glVertex2d(x2, y2);
	glVertex2d(x2, y1);
	glEnd();
}


void Painter::SetColor(Color color)
{
	struct
	{
		double r, g, b;
	} _color[]=
	{
		{ 1.0, 0.0, 0.0 }, // RED
		{ 0.0, 1.0, 0.0 }, // GREEN
		{0.0, 0.0, 1.0}	   // BLUE
	};
	glColor3d(_color[color].r, _color[color].g, _color[color].b);
}
