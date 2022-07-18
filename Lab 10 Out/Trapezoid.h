#pragma once
#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "Quadrilateral.h"

using namespace std;

class Trapezoid : public Quadrilateral
{

public:
    Trapezoid();
    Trapezoid(GenPoint a, GenPoint b, GenPoint c, GenPoint d, Color color);
    void setPoints(GenPoint a, GenPoint b, GenPoint c, GenPoint d);
    double getArea();
    void print();
};

#endif
