#include <iostream>
#include <cstring>
#include <fstream>
#include "graph1.h"
#include "Game.h"

using namespace std;


Game::Game()
{
	fileName = "";
	word = "";
}


string Game::getFileName()
{
	return fileName;
}
void Game::setFileName(string fn)
{
	fileName = fn;

}
void Game::setWord(int rand_no)
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
string Game::getWord()
{
	return word;

}
void Game::draw()
{
	//Display letters
	int startx = 100;
	int starty = 200;
	string letter = "";
	int length = 0;

	//Get length of word
	length = word.length();

	//Display white rectangle for each letter
	for (int i = 0; i < length; i++)
	{
		drawRect(startx, starty, 32, 32);
		startx += 33;
	}

	startx = 100;
	for (int i = 0; i < length; i++)
	{
		letter = "";

		letter += word[i];
		letter += ".bmp";
		displayBMP(letter, startx, starty);
		startx += 33;
	}

}
