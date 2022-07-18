#pragma once
#ifndef FLUID_H
#define FLUID_H

#include <string>
#include "GenPoint.h"
#include "Color.h"

using namespace std;

class Fluid
{
private:
    GenPoint start;
    GenPoint end;
    int fillLine;
    string fluidName;

public:
    Fluid();
    void setStart(GenPoint start);
    void setEnd(GenPoint end);
    void setFluidName(string name);
    void setFillLine(int fillLine);
    GenPoint getStart();
    GenPoint getEnd();
    int getFillLine();
    Color getColor();
    string getFluidName();
};

#endif 
