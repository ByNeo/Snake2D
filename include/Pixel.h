#ifndef PIXEL_H
#define PIXEL_H

#include "Shape.h"

const int LEFT	= 1;
const int RIGHT	= 2;
const int UP	= 3;
const int DOWN	= 4;


class Pixel : public Shape {
private:
	int distance;
	int direction;

public:
	Pixel();
	Dot		getFrontDot();
	void	move();
	
	int		getDistance();
	int		getDirection();
	void	setPosition(float x, float y);
	void	setDirection(int direction);

};


#endif