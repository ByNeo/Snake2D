#include "Field.h"


Field::Field()
{
	drawShape = GL_LINES;
	lineSpacing = 20;
	numberOfVLines = WIDTH / lineSpacing + 1;
	numberOfHLines = (HEIGHT-60) / lineSpacing + 1;
	
	color = Color(0.0f, 0.0f, 1.0f);
	pDots = new Dot[numberOfVLines*2 + numberOfHLines*2];

	// Vertical lines
	for(int i=0; i<numberOfVLines; i++)
	{
		pDots[numberOfDots].setCoordinat(i*lineSpacing, 0);
		numberOfDots++;

		pDots[numberOfDots].setCoordinat(i*lineSpacing, HEIGHT-60);
		numberOfDots++;
	}

	// Horizontal lines
	for(int i=0; i<numberOfHLines; i++)
	{
		pDots[numberOfDots].setCoordinat(0, i*lineSpacing);
		numberOfDots++;

		pDots[numberOfDots].setCoordinat(WIDTH, i*lineSpacing);
		numberOfDots++;
	}
}


Field::Field(int lineSpacing)
{
	drawShape = GL_LINES;
	this->lineSpacing = lineSpacing;
	numberOfVLines = WIDTH / lineSpacing + 1;
	numberOfHLines = (HEIGHT-60) / lineSpacing + 1;

	color = Color(0.0f, 1.0f, 0.0f);
	pDots = new Dot[numberOfVLines*2 + numberOfHLines*2];

	// Vertical lines
	for(int i=0; i<numberOfVLines; i++)
	{
		pDots[numberOfDots].setCoordinat(i*this->lineSpacing, 0);
		numberOfDots++;

		pDots[numberOfDots].setCoordinat(i*this->lineSpacing, HEIGHT-60);
		numberOfDots++;
	}

	// Horizontal lines
	for(int i=0; i<numberOfHLines; i++)
	{
		pDots[numberOfDots].setCoordinat(0, i*this->lineSpacing);
		numberOfDots++;

		pDots[numberOfDots].setCoordinat(WIDTH, i*this->lineSpacing);
		numberOfDots++;
	}
}


void Field::drawScoreTable()
{
	setColor( Color(70/255.0f, 130/255.0f, 180/255.0f) );
	
	color.use();
	glRectf(0.0f, HEIGHT-lineSpacing*3+1, WIDTH, HEIGHT);
	
	setColor( Color(176/255.0F, 196/255.0F, 222/255.0F) );
	color.use();
	glRectf(4.0f, HEIGHT-lineSpacing*3+5, WIDTH-4, HEIGHT-4);

	setColor( Color(0.0f, 0.0f, 1.0f) );

}