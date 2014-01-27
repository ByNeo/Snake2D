#ifndef SHAPE_H
#define SHAPE_H

#include "Dot.h"
#include "Color.h"


class Shape {
protected:
	int		drawShape;						// Kendimiz ekledik çizim þekli için
	int		numberOfDots;
	int		maxDots;
	Dot*	pDots;
	Color	color;

public:
	Shape();
	~Shape();

	void draw();
	void setColor(Color c);
	void addDot(float x, float y);

};


#endif