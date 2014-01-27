#ifndef SCORE_H
#define SCORE_H


class Score {
private:
	int score;
	int level;
	int reserve;
	int numberOfFood;

public:
	Score();

	int		getScore();
	int		getLevel();
	void	addScore();
	void	levelControl();

};


#endif