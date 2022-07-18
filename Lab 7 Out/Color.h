#pragma once
#ifndef COLOR_H
#define COLOR_H

class Color
{
private:
    int r;
    int g;
    int b;

public:
    Color();
    Color(int r, int g, int b);
    void setColor(int r, int g, int b);
    int getRed();
    int getGreen();
    int getBlue();

};

#endif
