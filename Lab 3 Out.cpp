//Harrison Bounds
//Lab 3 Out
//A game that lets the user "zap" bugs

#include <iostream>
#include <ctime>
#include "graph1.h"

//Function Prototypes
void initDisplay();
int getNoBugs();
int* getXCoords(int no_bugs);
int* getYCoords(int no_bugs);
int* displayObjects(int* x_coords, int* y_coords, int no_bugs);
int zapBugs(int* x_coords, int* y_coords, int* objects, int no_bugs);

using namespace std;

int main()
{
	//Variables
	int no_bugs = 0;
	int* x_coords = NULL;
	int* y_coords = NULL;
	int* objects = NULL;
	int score = 0;

	//Display Graphics Window
	displayGraphics();

	//Initialize seed
	srand(time(0));

	//Function Calls
	initDisplay();
	no_bugs = getNoBugs();
	x_coords = getXCoords(no_bugs);
	y_coords = getYCoords(no_bugs);
	objects = displayObjects(x_coords, y_coords, no_bugs);
	score = zapBugs(x_coords, y_coords, objects, no_bugs);
}

//Function Headers

void initDisplay()
{
	displayPNG("grass.png", 0, 0);

	drawRect(250, 0, 200, 40);
}

int getNoBugs()
{
	int no_bugs = 0;
	do
	{
		cout << "Enter # of bugs to Display <Between 5 and 20>: ";
		cin >> no_bugs;

	} while (no_bugs < 5 || no_bugs > 20);

	return no_bugs;
}

int* getXCoords(int no_bugs)
{

	int bug_width = 64;

	int* x_coords = new int(no_bugs);

	for (int i = 0; i < no_bugs; i++)
	{
		x_coords[i] = rand() % (640 - bug_width);
	}

	return (x_coords);
}

int* getYCoords(int no_bugs)
{

	int bug_height = 64;

	int* y_coords = new int(no_bugs);

	for (int i = 0; i < no_bugs; i++)
	{
		y_coords[i] = rand() % ((400 + 40) - bug_height);
	}

	return (y_coords);
}


int* displayObjects(int* x_coords, int* y_coords, int no_bugs)
{

	int* objects = new int(no_bugs);

	for (int i = 0; i < no_bugs; i++)
	{
		objects[i] = displayPNG(("bugs.png"), x_coords[i], y_coords[i]);
	}

	return(objects);
}

int zapBugs(int* x_coords, int* y_coords, int* objects, int no_bugs)
{
	int i = 0;
	int radius = 10;
	int bug_width = 64;
	int bug_height = 64;
	int x_guess = 0;
	int y_guess = 0;
	int score = 0;
	int shots = 0;

	for (i = 0; i < (2 * no_bugs); i++)
	{
		gout << setPos(285, 20) << setColor(0, 0, 0) << "Score: " << score << endg;
		gout << setPos(375, 20) << setColor(0, 0, 0) << "Shots: " << shots << endg;

		if (score == no_bugs)
		{
			drawRect(250, 0, 200, 40);
			gout << setPos(285, 20) << setColor(0, 0, 0) << "Winner!" << endg;
		}
		else if (shots == (2 * no_bugs))
		{
			drawRect(250, 0, 200, 40);
			gout << setPos(285, 20) << setColor(0, 0, 0) << "Game Over!" << endg;
		}
		cout << "Enter x/y coordinates: ";
		cin >> x_guess >> y_guess;

		for (int j = 0; j < radius; j++)
		{
			setColor(drawCircle((radius - j), x_guess, y_guess), 0, 0, 0);
		}

		if ((x_guess > x_coords[1 - no_bugs]) && (x_guess < x_coords[1 - no_bugs] + bug_width) && (y_guess > y_coords[1 - no_bugs]) && (y_guess < y_coords[1 - no_bugs] + bug_height))
		{
			Sleep(1000);
			removeObject(no_bugs);
			score += 1;
		}

		++shots;

		
	}





	return score;
}
	