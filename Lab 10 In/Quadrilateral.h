#pragma once
#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

#include "GenPoint.h"
#include "Color.h"

using namespace std;

class Quadrilateral
{
protected:

    GenPoint a;
    GenPoint b;
    GenPoint c;
    GenPoint d;
    Color color;

public:
    Quadrilateral(); //Sets all points/colors to 0
    void setPoints(GenPoint a, GenPoint b, GenPoint c, GenPoint d);
    void setCol(Color color);
    double getPerimeter();
    void print();
    void draw();
};

#endif
