#ifndef DOT_H
#define DOT_H

#include <freeglut\freeglut.h>


class Dot {
private:
	float x;
	float y;

public:
	Dot();
	Dot(float x, float y);
	
	void	vertex();
	bool	operator==(Dot right);

	float	getX();
	float	getY();
	void	setCoordinat(int x, int y);

};

#endif