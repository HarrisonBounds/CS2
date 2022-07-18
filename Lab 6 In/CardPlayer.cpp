//Harrison Bounds
//Lab 6 In
//Display card hands of the player and dealer and 
//see who has the higher score

#include <iostream>
#include "graph1.h"
#include "CardPlayer.h"

CardPlayer::CardPlayer()
{
	//Implement the default Constructor
	color = 'r';
	noCards = 0;
	hand = NULL;
}

CardPlayer::~CardPlayer()
{
	delete[] hand;
}
void CardPlayer::setNoCards(int noCards)
{
	if (noCards < 5)
		this->noCards = 5;
	else if (noCards > 10)
		this->noCards = 10;
	else
		this->noCards = noCards;

	hand = new int[this->noCards];
}

int CardPlayer::getNoCards()
{
	return noCards;
}

void CardPlayer::setColor(char color)
{
	this-> color = color;
}

void CardPlayer::displayHand(int x, int y)
{
	string fileName = "";

	if (color == 'r')
		fileName = "d";
	else
		fileName = "c";

	for (int i = 0; i < noCards; i++)
	{
		displayBMP(fileName + to_string(hand[i]) + ".bmp", x, y + 20 * i);
	}

}

int CardPlayer::computeScore()
{
	int score = 0;
	int total_score = 0;

	for (int i = 0; i < noCards; i++)
	{
		if (hand[i] == 10 || hand[i] == 11 || hand[i] == 12 || hand[i] == 13)
		{
			score = 10;
		}
		else if (hand[i] == 14)
		{
			score = 11;
		}
		else
		{
			score = hand[i];
		}

		total_score += score;
	}

	return total_score;
}

//Implemented for you
void CardPlayer::deal()
{
	bool duplicate = false;


	for (int i = 0; i < noCards; i++)
	{
		hand[i] = rand() % 13 + 2;

		do
		{
			duplicate = false;
			for (int j = 0; j < i; j++)
			{
				if (hand[i] == hand[j])
				{
					hand[i] = rand() % 13 + 2;
					duplicate = true;
					break;
				}
			}
		} while (duplicate);
	}

}

