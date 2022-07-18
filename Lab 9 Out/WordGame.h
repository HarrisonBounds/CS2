#pragma once
#ifndef WORDGAME_H
#define WORDGAME_H

using namespace std;

class WordGame
{
private:
    string fileName;
    string word;

public:
    WordGame();
    string getFileName();
    void setFileName(string fn);
    void setWord(int rand_no);
    string getWord();
    void draw();
    int play();
};

#endif
