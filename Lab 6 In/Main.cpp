#include <iostream>
#include "graph1.h"
#include "CardPlayer.h"
#include<ctime>

using namespace std;

int main()
{
    //Variable Declaration/Initialization
    int noCards = 0;
    char color = 'r';
    CardPlayer player1;
    CardPlayer dealer;
    int player_score = 0;
    int dealer_score = 0;

    srand(time(0));

    //Display Graphics
    displayGraphics();

    //Prompt for the suit color
    cout << "Enter the suit color (r for red suits, b for black suits): ";
    cin >> color;

    //Set the color
    if (color == 'r')
    {
        player1.setColor(color);
        dealer.setColor('b');
    }
    else
    {
        player1.setColor('b');
        dealer.setColor(color);
    }

    //Prompt for the number of cards
    cout << "Enter the number of cards to deal to each player (>= 5 but <= 10): ";
    cin >> noCards;


    //Set the nuCards (will need to dynamically allocate the hand inside of this method)
    player1.setNoCards(noCards);

    dealer.setNoCards(noCards);

    //Deal the cards
    player1.deal();

    dealer.deal();

    //Display the cards
    player1.displayHand(150, 100);

    dealer.displayHand(250, 100);

    //Display the score
    player_score = player1.computeScore();

    dealer_score = dealer.computeScore();

    gout << setPos(150, 70) << "Player 1" << endg;
    gout << setPos(250, 70) << "Dealer" << endg;

    gout << setPos(150, 100 + (noCards * 20) + 100) << "Score: " << player_score << endg;
    gout << setPos(250, 100 + (noCards * 20) + 100) << "Score: " << dealer_score << endg;



    return 0;
}
