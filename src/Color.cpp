#include <freeglut\freeglut.h>
#include "Color.h"


Color::Color()
{
	red = 1.0f;
	green = 0.0f;
	blue = 0.0f;
}


Color::Color(float r, float g, float b)
{
	red = r;
	green = g;
	blue = b;
}


void Color::use()
{
	glColor3f(red, green, blue);
}


float Color::getR()
{
	return red;
}


float Color::getG()
{
	return green;
}


float Color::getB()
{
	return blue;
}