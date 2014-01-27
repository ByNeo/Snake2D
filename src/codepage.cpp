#include <string>
#include <sstream>
#include <windows.h>
#include "Snake.h"
#include "Field.h"

// MSVC Console close
//#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

using namespace std;

int		time = 0;
Field	grid;
Snake	snake;
Score	highScore;

/*
*	Prototype functions
*/
static void renderScene(void);
static void InitializeGlutCallbacks();
void specialKeys(int key, int x, int y);
void keyboard(unsigned char key, int x, int y);
void displayWrite(float x, float y, void* font, const char* writing, Color rgb);


int main(int argc, char** argv)
{
	// Console close..
	FreeConsole();

	//	This function, is used to initialize the GLUT library.
	glutInit(&argc, argv);

	// This function, set the initial window size respectively.
	glutInitWindowSize(WIDTH, HEIGHT);
	
	// Setting the display mode
	// glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	
	// The title is given, and the window is created
	glutCreateWindow("Snake 2D");

	// This function, sets the keyboard callback for the current window.
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeys);

	InitializeGlutCallbacks();


	// TThis function, sets the global idle callback.
	//glutIdleFunc(display);

	// This function, enters the GLUT event processing loop.
	glutMainLoop();


	return EXIT_SUCCESS;
}


static void renderScene()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(	0,WIDTH,0,HEIGHT);

	// This function clears buffers to preset values.
	// glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT);

	// Draws the grid and score table
	grid.draw();
	grid.drawScoreTable();

	// Does a snake hits the ground?
	if(!snake.collision(highScore))
	{
		// 
		snake.move();
	}
	else
	{
		// 
		displayWrite(340.0f, 301.0f, GLUT_BITMAP_TIMES_ROMAN_24, "GAME OVER\0", Color(1.0f, 0.0f, 0.0f));
	}
	// Snake draws
	snake.draw();

	// Prints level and score
	ostringstream outLvl, outScr;
	outScr << highScore.getScore();
	outLvl << highScore.getLevel();
	string str = "LEVEL: " + outLvl.str() + "                     SCORE: " + outScr.str();
	displayWrite( 220.0f, 565.0f, GLUT_BITMAP_TIMES_ROMAN_24, str.c_str(), Color(0.0f, 0.0f, 0.0f) );
	
	// This, swaps the buffers of the current window if double buffered.
	// glutSwapBuffers();

	glFlush();
 
	// This is a counter. But slowly move snake and regeneration of the program
	int setSpeed = ( highScore.getLevel()*15 );
	setSpeed = (setSpeed <= 180) ? setSpeed : 180;
	while( GetTickCount()-time <= 200-setSpeed );
	time = GetTickCount();

	// This funciton, marks the current window as needing to be redisplayed
	glutPostRedisplay();
}


static void InitializeGlutCallbacks()
{
	// Sets the display callback for the current window.
	glutDisplayFunc(renderScene);
}


void specialKeys(int key, int x, int y)
{
	snake.specialKeys(key);
}


void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 'e':
		case 'E':
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			break;
		case 'f':
		case 'F':
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);	
			break;
		case '\x1B':
			exit(EXIT_SUCCESS);
			break;
	}

	snake.normalKeys(key);
}


void displayWrite(float x, float y, void *font, const char* writing, Color rgb)
{  
	glColor3f( rgb.getR(), rgb.getG(), rgb.getB() ); 
	glRasterPos2f(x, y);
	
	// Generally more efficient for strings of characters.
	glutBitmapString(font,(unsigned char*)writing);

	// But that can also be
	/*for(int i=0; writing[i] != '\0'; i++)
		glutBitmapCharacter(font, writing[i]);*/
}