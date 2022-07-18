#pragma once

#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

using namespace std;

class Circle : public Shape
{
protected:
    int radius;
    GenPoint center;
    const static double PI;


public:
    Circle();
    Circle(GenPoint center, int radius, Color c);
    void setCenter(GenPoint center);
    void setRadius(int radius);
    double getPerimeter();
    double getArea();
    void print();
    void draw();
};

#endif

