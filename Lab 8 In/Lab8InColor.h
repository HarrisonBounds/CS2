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
    void setCol(int r, int g, int b);
    int getRed();
    int getGreen();
    int getBlue();
    Color operator+(Color right);
    Color operator-(Color right);
    Color operator/(int right);
    Color operator*(int right);
    bool operator==(Color right);
    bool operator!=(Color right);
    void operator=(Color right);
    Color operator!();
    void draw(int x, int y, int w, int h);
};

#endif

