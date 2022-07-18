//Harrison Bounds
//Lab 2 Out
//This program plays a card game against you and the dealer
//Whoever has the higher score, wins!

#include<iostream>
#include"graph1.h"
#include<ctime>


using namespace std; 

void getWager(int* wager);
void deal(int* pc1_no, int* pc2_no, int* deal1_no, int* deal2_no);
int computeScore(int card1_no, int card2_no);
void displayResults(int pc1_no, int pc2_no, int deal1_no, int deal2_no, int player_score, int dealer_score);

int main()
{
	int wager = 0;
	int pc1_no, pc2_no, deal1_no, deal2_no = 0;
	int player_score = 0;
	int dealer_score = 0;
	int card1_no = 0, card2_no = 0;
	bool repeat;

	do
	{
		srand(time(0));

		displayGraphics();

		getWager(&wager);

		deal(&pc1_no, &pc2_no, &deal1_no, &deal2_no);

		card1_no = pc1_no;
		card2_no = pc2_no;

		player_score = computeScore(card1_no, card2_no);

		card1_no = deal1_no;
		card2_no = deal2_no;

		dealer_score = computeScore(card1_no, card2_no);

		displayResults(pc1_no, pc2_no, deal1_no, deal2_no, player_score, dealer_score);

		cout << "Do you wish to run the program again? <1 for yes> <0 for no>:  ";
		cin >> repeat;

		clearGraphics();
		system("cls");

	} while (repeat);
}

void getWager(int* wager)
{
	do
	{
		cout << "Enter your wager < $5 minimum > : ";
		cin >> *wager;
	} while (*wager < 5);
}

void deal(int* pc1_no, int* pc2_no, int* deal1_no, int* deal2_no)
{
	*pc1_no = rand() % 12 + 2;

	*pc2_no = rand() % 12 + 2;

	*deal1_no = rand() % 12 + 2;

	*deal2_no = rand() % 12 + 2;
}

int computeScore(int card1_no, int card2_no)
{
	int total = 0;

	if (card1_no == 11 || card1_no == 12 || card1_no == 13)
	{
		card1_no = 10;
		total += card1_no;
	}
	else if (card1_no == 14)
	{
		card1_no = 11;
		total += card1_no;
	}
	else
	{
		total += card1_no;
	}
	if (card2_no == 11 || card2_no == 12 || card2_no == 13)
	{
		card2_no = 10;
		total += card2_no;
	}
	else if (card2_no == 14)
	{
		card2_no = 11;
		total += card2_no;
	}
	else
	{
		total += card2_no;
	}
	
	return total;
}

void displayResults(int pc1_no, int pc2_no, int deal1_no, int deal2_no, int player_score, int dealer_score)
{
	gout << setPos(75, 90) << "Your Cards" << endg;
	displayBMP("back.bmp", 75, 100);

	gout << setPos(400, 90) << "Dealer Cards" << endg;
	displayBMP("back.bmp", 400, 100);

	//Display your cards
	displayBMP("h" + to_string(pc1_no) + ".bmp", 150, 100);
	displayBMP("d" + to_string(pc2_no) + ".bmp", 225, 100);

	//Display Dealer's cards
	displayBMP("c" + to_string(deal1_no) + ".bmp", 475, 100);
	displayBMP("s" + to_string(deal2_no) + ".bmp", 550, 100);

	gout << setPos(75, 250) << "Your Total: " << player_score << endg;

	gout << setPos(400, 250) << "Dealer Total: " << dealer_score << endg;

	if(player_score > dealer_score)
		gout << setPos(290, 300) << "You Win!" << endg;
	else if(player_score < dealer_score)
		gout << setPos(290, 300) << "You Lose!" << endg;
	else if(player_score == dealer_score)
		gout << setPos(290, 300) << "Tie!" << endg;

}



