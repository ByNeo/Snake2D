#include <cstdlib>
#include <ctime>
#include "Snake.h"


Snake::Snake()
{
	numberOfPixel = 0;
	for(int i=0; i<6; i++)
	{
		Pixels[i] = new Pixel;
		Pixels[i]->setPosition(200-Pixels[i]->getDistance() * i, 200);
		numberOfPixel++;
	}

	feedRefresh();
}


Snake::~Snake()
{
	for(int i=0; i<MAX_NUMBEROFPIXEL; i++)
		delete Pixels[i];
}


void Snake::draw()
{
	for(int i=0; i<numberOfPixel; i++)
	{
		Pixels[i]->draw();
	}

	food.draw();
}


void Snake::normalKeys(unsigned char key)
{
	switch (key)
	{
		case 'a':
		case 'A':
			if(!(Pixels[0]->getDirection() == RIGHT))
				Pixels[0]->setDirection(LEFT);
			break;

		case 'd':
		case 'D':
			if(!(Pixels[0]->getDirection() == LEFT))
				Pixels[0]->setDirection(RIGHT);
			break;

		case 'w':
		case 'W':
			if(!(Pixels[0]->getDirection() == DOWN))
				Pixels[0]->setDirection(UP);
			break;

		case 's':
		case 'S':
			if(!(Pixels[0]->getDirection() == UP))
				Pixels[0]->setDirection(DOWN);
			break;
	}
}


void Snake::specialKeys(int key)
{
	switch (key)
	{
		case GLUT_KEY_LEFT:
			if(!(Pixels[0]->getDirection() == RIGHT))
				Pixels[0]->setDirection(LEFT);
			break;

		case GLUT_KEY_RIGHT:
			if(!(Pixels[0]->getDirection() == LEFT))
				Pixels[0]->setDirection(RIGHT);
			break;

		case GLUT_KEY_UP:
			if(!(Pixels[0]->getDirection() == DOWN))
				Pixels[0]->setDirection(UP);
			break;

		case GLUT_KEY_DOWN:
			if(!(Pixels[0]->getDirection() == UP))
				Pixels[0]->setDirection(DOWN);
			break;
	}
}


void Snake::addPixel()
{
	float operatorX, operatorY;
	Pixels[numberOfPixel] = new Pixel;

	switch(Pixels[numberOfPixel-1]->getDirection())
	{
		case LEFT:
			operatorX = +1;
			operatorY = 0;
			break;

		case RIGHT:
			operatorX = -1;
			operatorY = 0;
			break;

		case UP:
			operatorX = 0;
			operatorY = -1;
			break;

		case DOWN:
			operatorX = 0;
			operatorY = +1;
			break;
	}

	float posX = (Pixels[numberOfPixel-1]->getFrontDot().getX()) + operatorX*Pixels[numberOfPixel-1]->getDistance();
	float posY = (Pixels[numberOfPixel-1]->getFrontDot().getY()) + operatorY*Pixels[numberOfPixel-1]->getDistance();
	
	Pixels[numberOfPixel]->setPosition(posX, posY);
	Pixels[numberOfPixel]->setDirection( Pixels[numberOfPixel-1]->getDirection() );
	numberOfPixel++;
}


void Snake::feedRefresh()
{
	// MSVC'de çalýþýyor ama MinGW'de main içinde bulunmadýðýndan hata veriyor.
	/*srand(time(NULL));*/

	// Yem yýlan üzerinde oluþturuluyor mu kontrol ediliyor..
	// Eðer yýlan üzerinde ise yeniden koordinat alýnýyor..
	float tempX, tempY;
	bool control;

	do {
		control = false;
		tempX = (rand()%40) * 20.0F;
		tempY = (rand()%27) * 20.0F;
		
		for(int i=0; i<numberOfPixel; i++)
		{
			if( Pixels[i]->getFrontDot() == Dot(tempX, tempY) )
				control = true;
		}
	}while(control);

	food.setPosition(tempX, tempY);
	food.setColor( Color(154/255.0F, 205/255.0F, 50/255.0F) );
}


bool Snake::collision(Score& _hScore)
{
	// Snake eats the bait
	if(Pixels[0]->getFrontDot() == food.getFrontDot())
	{
		_hScore.addScore();
		_hScore.levelControl();
		addPixel();
		feedRefresh();
	}


	// If the snake hits the tail
	for(int i=1; i<numberOfPixel; i++)
	{
		if(	Pixels[0]->getFrontDot() == Pixels[i]->getFrontDot() )
			return true;
	}


	// If the snake hits the wall
	if(		Pixels[0]->getFrontDot().getX() >= 0 && Pixels[0]->getFrontDot().getX() < 800
		&&	Pixels[0]->getFrontDot().getY() >= 0 && Pixels[0]->getFrontDot().getY() < 540 )
	{
		return false;
	}
	else
		return true;
}


void Snake::move()
{	
	for(int i=0; i<numberOfPixel; i++)
	{
		Pixels[i]->move();
	}

	for(int i=numberOfPixel-1; i>0; i--)
	{
		Pixels[i]->setDirection( Pixels[i-1]->getDirection() );
	}
}