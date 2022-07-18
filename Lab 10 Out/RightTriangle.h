#pragma once
#ifndef RIGHT_TRIANGLE_H
#define RIGHT_TRIANGLE_H

#include "Triangle.h"

using namespace std;

class RightTriangle : public Triangle
{

public:

    RightTriangle();
    RightTriangle(GenPoint vertex, int height, int base, Color color);
    void print();
};

#endif
