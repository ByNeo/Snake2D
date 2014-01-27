#include "Shape.h"


Shape::Shape()
{
	drawShape = GL_LINES;
	numberOfDots = 0;
	maxDots = 0;
	pDots = NULL;
	color = Color(1.0f, 0.0f, 0.0f);
}


Shape::~Shape()
{
	delete[] pDots;
	maxDots = numberOfDots = 0;
	pDots = NULL;
}


void Shape::draw()
{
	glBegin(drawShape);

	color.use();
	for(int i=0; i<numberOfDots; i++)
		pDots[i].vertex();

	glEnd();
}


void Shape::setColor(Color c)
{
	color = c;
}


void Shape::addDot(float x, float y)
{
	if(numberOfDots == maxDots)
		return;

	pDots[numberOfDots].setCoordinat(x, y);

	numberOfDots++;
}