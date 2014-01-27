#ifndef COLOR_H
#define COLOR_H


class Color {
private:
	float red;
	float green;
	float blue;

public:
	Color();
	Color(float r, float g, float b);
	
	void use();

	float getR();
	float getG();
	float getB();

};


#endif