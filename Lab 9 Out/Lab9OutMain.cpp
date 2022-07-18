//Harrison Bounds
//Lab 9 Out
//Play a word guessing game

#include <iostream>
#include "WordGame.h"
#include <cstring>
#include <fstream>
#include <ctime>
#include "graph1.h"

using namespace std;

int main()
{
	//Variables
	int rand_no = 0;
	string fn;
	char repeat = 'y';
	WordGame WordGame;

	//Display Graphics
	displayGraphics();

	//Initialize RNG
	srand(time(0));

	do
	{

	//Generate Random Number between 0 and 1148
	rand_no = rand() % 1149;

	//Prompt for fn
	cout << "Enter filename that contains words: ";
	cin >> fn;

	//Set the filename
	WordGame.setFileName(fn);

	//Set the word
	WordGame.setWord(rand_no);

	//Draw the blank rectangles
	WordGame.draw();

	//Invoke play method
	WordGame.play();
 
	cout << "Repeat? (y/n): ";
	cin >> repeat;

	//Clear screen
	system("cls");
	clearGraphics();

} while ((repeat == 'y') || (repeat == 'Y'));


}
