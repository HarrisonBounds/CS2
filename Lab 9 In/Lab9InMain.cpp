//Harrion Bounds
//Lab 9 IN
//Process text information stored in a file

#include <iostream>
#include <ctime>
#include "Game.h"
#include "graph1.h"

using namespace std;

int main()
{
    //Variable Declaration/Initialization
    int rand_no = 0;
    string fn;
    char repeat = 'y';
    Game game;

    //Display graphics
    displayGraphics();

    //Initialize random # generator
    srand(time(0));

    //Run program as many times as desired
    do
    {

        //Generate random #
        rand_no = rand() % 1149;

        //Prompt for fn
        cout << "Enter filename that contains words: ";
        cin >> fn;

        //Set the filename
        game.setFileName(fn);

        //Set the word
        game.setWord(rand_no);

        //Draw the scene
        game.draw();

        //Get the word
        string temp = game.getWord();

        //Display the actual word
        cout << "Random word is: " << temp << endl;

        cout << "Repeat? (y/n): ";
        cin >> repeat;

        //Clear screen
        system("cls");
        clearGraphics();



    } while ((repeat == 'y') || (repeat == 'Y'));

    return 0;
}

