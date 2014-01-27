#include "Pixel.h"


Pixel::Pixel()
{
	distance = 20;
	direction = RIGHT;
	numberOfDots = 6;
	drawShape = GL_TRIANGLES;
	pDots = new Dot[numberOfDots];

	setPosition(200, 200);

	float r = (rand()%255) / 255.0F;
	float g = (rand()%255) / 255.0F;
	float b = (rand()%255) / 255.0F;

	color = Color(r, g, b);
}


Dot Pixel::getFrontDot()
{
	return pDots[1];
}


void Pixel::move()
{
	switch(direction)
	{
		case LEFT:
			for(int i=0; i<numberOfDots; i++)
				pDots[i].setCoordinat( pDots[i].getX() - distance, pDots[i].getY() );
			break;

		case RIGHT:
			for(int i=0; i<numberOfDots; i++)
				pDots[i].setCoordinat( pDots[i].getX() + distance, pDots[i].getY() );
			break;

		case UP:
			for(int i=0; i<numberOfDots; i++)
				pDots[i].setCoordinat( pDots[i].getX(), pDots[i].getY() + distance );
			break;
	
		case DOWN:
			for(int i=0; i<numberOfDots; i++)
				pDots[i].setCoordinat( pDots[i].getX(), pDots[i].getY() - distance );
			break;
	}
}


int Pixel::getDistance()
{
	return distance;
}


int Pixel::getDirection()
{
	return direction;
}


void Pixel::setPosition(float x, float y)
{
	pDots[0] = Dot(x, y + distance);
	pDots[1] = Dot(x, y);
	pDots[2] = Dot(x + distance, y);

	pDots[3] = Dot(x + distance, y + distance);
	pDots[4] = Dot(x,y + distance);
	pDots[5] = Dot(x + distance, y);
}


void Pixel::setDirection(int direction)
{
	this->direction = direction;
}