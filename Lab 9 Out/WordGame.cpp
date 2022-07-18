#include <iostream>
#include "WordGame.h"
#include <cstring>
#include <fstream>
#include "graph1.h"

using namespace std;

WordGame::WordGame()
{
	fileName = "";
	word = "";
}

string WordGame::getFileName() 
{
	return fileName;
}

string WordGame::getWord()
{
	return word;
}

void WordGame::setFileName(string fn)
{
	fileName = fn;
}

void WordGame::setWord(int rand_no)
{
	//Variables
	string temp_word = "";
	int counter = 0;

	//Open a file for reading
	fstream in_file(fileName, ios::in);


	//Test the file for opening
	if (!in_file)
		cout << "Error, can not open the file";


	//Read the words from the file
	while (true)
	{
		//Read one word at a time
		in_file >> temp_word;

		//test for the end of the file
		if (in_file.eof())
			break;

		//Test that we have reached a random word
		if (counter == rand_no)
		{
			word = temp_word;
			break;
		}

		//increment word counter if it has not reached the random word yet
		counter++;
	}

	//close the file
	in_file.close();
}

void WordGame::draw()
{
	//Variables
	int x = 100;
	int y = 200;
	int length = 0;

	//Get length of the word
	length = word.length();

	//Display white rectangles
	for (int i = 0; i < length; i++)
	{
		drawRect(x, y, 32, 32);
		x += 33;
	}

	//Leave rectangle of the screen for 2 seconds
	Sleep(2000);

}

int WordGame::play()
{
	//Variables
	int x = 100;
	int y = 200;
	int length = 0;
	int score = 0;
	string guess = "";
	string wordGuess = word;
	string letter = "";
	char shown = '0';
	int guessNum = 0;
	

	//Get length of the word
	length = word.length();

	
	
	//Displays the vowels of the word
	for (int i = 0; i < length; i++)
	{
		letter = "";

		letter += word[i];
		letter += ".bmp";

		if (i == 0)
		{
			//Displays the first letter of the random word
			displayBMP(letter, x, y);
			wordGuess[i] = shown;
			
		}
		//Displays the vowels of the random word
		else if(wordGuess[i] == 'a' || wordGuess[i] == 'e' || wordGuess[i] == 'i' || wordGuess[i] == 'o' || wordGuess[i] == 'u' || wordGuess[i] == 'y')
		{
			displayBMP(letter, x, y);
			wordGuess[i] = shown;
		}
		
		x += 33;
	}
	
	//Counts all the shown words
	int j = 0;
	for (int i = 0; i < length; i++)
	{
		if (wordGuess[i] == shown)
		{
			j++;
		}
	}

	

	for (int i = 0; i < length - j; i++)
	{
		x = 100;

		cout << "Guess #" << i + 1 << endl << "What is the word?: ";
		cin >> guess;

		guessNum += 1;

		

		if (guess == word)
		{
			gout << setPos(100, 120) << "!!!Correct!!!" << endg;
			gout << setPos(100, 133) << "Number of Guesses: " << guessNum << endg;
			break;
		}
		
		
		else if(i % 2 == 0 && guess != word)
		{
			gout << setPos(100, 120) << "!!!Incorrect!!!" << endg;
			gout << setPos(100, 133) << "Number of Guesses: " << guessNum << endg;

			for (int i = 0; i < length; i++)
			{
				if (wordGuess[i] != shown)
				{
					letter = "";
					letter += word[i];
					letter += ".bmp";

					displayBMP(letter, x, y);
					wordGuess[i] = shown;
					break;
				}
				x += 33;
			}
		}
		else if (i % 2 == 1 && guess != word)
		{
			gout << setPos(100, 120) << "!!!Incorrect!!!" << endg;
			gout << setPos(100, 133) << "Number of Guesses: " << guessNum << endg;

			x = 100 + (length - 1) * 33;

			for (int i = length - 1; i > 0; i--)
			{
				letter = "";
				letter += word[i];
				letter += ".bmp";

				if (wordGuess[i] != shown)
				{
					displayBMP(letter, x, y);
					wordGuess[i] = shown;
					break;
				}
				x -= 33;
			}

		}
		
	}

	if (guess != word)
	{
		gout << setPos(100, 120) << "GAME OVER" << endg;
		gout << setPos(100, 133) << "Number of Guesses: " << guessNum << endg;
	}

	

	//Calculates score for every hidden letter left
	for (int i = 0; i < length; i++)
	{
		if (wordGuess[i] != shown)
		{
			score += 10;
		}
	}

	gout << setPos(100, 145) << "Score: " << score << endg;

	return score;
}