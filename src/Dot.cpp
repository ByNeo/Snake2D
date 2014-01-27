#include "Dot.h"


// Constructor function assigns initial values ​​to the x and y variables.
Dot::Dot()
{
	x = y = 0.0f;
}


/*
	Constructor function assigns initial values ​​to the x and y variables.

	@Param	x	Is assigned to the variable x
	@Param	y	Is assigned to the variable y
*/
Dot::Dot(float x, float y)
{
	this->x = x;
	this->y = y;
}


// Coordinates draws
void Dot::vertex()
{
	glVertex2f(x, y);
}


// (==) operator overloading.
// On the right side is given as a parameter.
bool Dot::operator==(Dot right)
{
	if(x==right.x && y==right.y)
		return true;
	
	return false;
}


/*
*	@return		Returns the x coordinate
*/
float Dot::getX()
{
	return x;
}


/*
*	@return		Returns the y coordinate
*/
float Dot::getY()
{
	return y;
}


/*
*	Change the object's coordinates.
*/
void Dot::setCoordinat(int x, int y)
{
	this->x = x;
	this->y = y;
}