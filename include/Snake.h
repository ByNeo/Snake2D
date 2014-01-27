#ifndef SNAKE_H
#define SNAKE_H

#include "Score.h"
#include "Pixel.h"

const int MAX_NUMBEROFPIXEL = 255;


class Snake {
private:
	int		numberOfPixel;
	Pixel*	Pixels[MAX_NUMBEROFPIXEL];
	Pixel	food;

public:
	Snake();
	~Snake();

	void draw();
	void normalKeys(unsigned char key);
	void specialKeys(int key);
	void addPixel();
	void feedRefresh();
	bool collision(Score& _score);
	void move();

};


#endif