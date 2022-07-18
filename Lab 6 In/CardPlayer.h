#pragma once
#ifndef CARDPLAYER_H
#define CARDPLAYER_H


class CardPlayer
{
private:

	char color;
	int  noCards;
	int* hand;

public:
	CardPlayer();
	~CardPlayer();
	void setNoCards(int noCards);
	int getNoCards();
	void setColor(char color);
	void displayHand(int x, int y);
	int computeScore();
	void deal();
};

#endif
