#pragma once
#ifndef SHAPE_H
#define SHAPE_H

#include "GenPoint.h"
#include "Color.h"

using namespace std;

class Shape
{
protected:
    Color color;  //Color class used in lab7in

public:
    Shape();  //Default Constructor - sets color to (0,0,0)
    Color getColor();  //Getter for Color
    void setCol(Color color); //Setter for Color
    virtual double getPerimeter() = 0;
    virtual void print() = 0;
    virtual void draw() = 0;

};

#endif
