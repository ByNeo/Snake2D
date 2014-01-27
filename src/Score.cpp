#include "Score.h"


Score::Score()
{
	level = 1;
	reserve = 10;
	score = numberOfFood = 0;
}


int Score::getScore()
{
	return score;
}


int Score::getLevel()
{
	return level;
}


void Score::addScore()
{
	numberOfFood++;
	score = numberOfFood*10;
}


void Score::levelControl()
{
	int temp = (level <= 7) ? level : 4;

	if( (numberOfFood == reserve) )
	{
		level++;
		reserve += (10 - temp);
	}
}