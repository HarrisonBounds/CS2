//Harrison Bounds
//Lab 2 In
//Simulates the rolling of a set of dice

#include <iostream>
#include <ctime>
#include "graph1.h"

using namespace std;

//Protoypes
void getDiceCount(int* noDice);
void rollDice(int* dice, int noDice);
void computeScore(int* dice, int noDice, int* score);
void displayResults(int* dice, int noDice, int score);

int main()
{
	//Variable Declaration/Initialization
	int noDice = 0;
	const int MAX_DICE = 5;
	int dice[MAX_DICE] = { 0 };
	int score = 0;
	char repeat;

	do
	{
		//Initialize random number generator 
		srand(time(0));

		//Display Graphics
		displayGraphics();

		//1. Get the number of dice to roll
		getDiceCount(&noDice);

		//2. Roll the Dice (i.e., generates a random number for each dice
		rollDice(dice, noDice);

		//3. Compute the score
		computeScore(dice, noDice, &score);

		//4. Display the dice and results
		displayResults(dice, noDice, score);

		cout << "Would you like to run your code again?";
		cin >> repeat; 

		clearGraphics();
		system("cls");

	} while (repeat == 'Y' || repeat == 'y');

	return 0;

}

//Functions
void getDiceCount(int* noDice)
{
	//Prompts for the number of Dice to display and stores in the noDice variable
	//User input should be between 1 and 5 inclusively – reprompt if not within range
	do
	{
		cout << "What is the number of dice? <Between 1 and 5>:  ";
		cin >> *noDice;

		if (*noDice < 1 || *noDice > 5)
			cout << "Please enter a correct number" << endl;

	} while (*noDice < 1 || *noDice > 5);
	//perform data validation here, values should be between 1 and 5 inclusively
}


void rollDice(int* dice, int noDice)
{
	//Generates noDice random numbers corresponding to the rolling of the dice
	//Each random number is stored in the dice parameter
	//Each random number should be stored 

	for (int i = 0; i < noDice; i++)
	{
		dice[i] = rand() % 6 + 1;
	}

}

void computeScore(int* dice, int noDice, int* score)
{
	//Variable Declaration
	int i = 0;
	*score = 0;

	//Adds up each random number stored in the dice array
	//Stores the result in the score parameter

	for (int i = 0; i < noDice; i++)
	{
		*score += dice[i];
	}

}

void displayResults(int* dice, int noDice, int score)
{
	//Display each Die starting at 100,100
	//Each Die has a width of 104
	//Display the Score at (50,225)
	int x = 10;
	int y = 100;

	for (int i = 0; i < noDice; i++)
	{
		displayPNG(to_string(dice[i]) + "Die.PNG", x, y);
		x += 120;
	}

	gout << setPos(50, 225) << "Score: " << score << setColor(255, 0, 0) << endg;
}
