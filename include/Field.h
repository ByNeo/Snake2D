#ifndef FIELD_H
#define FIELD_H

#include "Shape.h"


const int HEIGHT = 600;
const int WIDTH  = 800;

class Field : public Shape {
private:
	int lineSpacing;
	int numberOfVLines;
	int numberOfHLines;

public:
	Field();
	Field(int lineSpacing);

	void drawScoreTable();

};


#endif