#include <string>
#include "GenPoint.h"
#include "Color.h"
#include "Fluid.h"

using namespace std;

Fluid::Fluid()
{
	start.setPoint(0, 0);
	end.setPoint(0, 0);
	fillLine = 0;
	fluidName = "";
}

void Fluid::setStart(GenPoint start)
{
	this->start.setPoint(start.getX(), start.getY());
}

void Fluid::setEnd(GenPoint end)
{
	this->end.setPoint(end.getX(), end.getY());
}

void Fluid::setFluidName(string name)
{
	this->fluidName = name;
}

void Fluid::setFillLine(int fillLine)
{
	this->fillLine = fillLine;
}

GenPoint Fluid::getStart()
{
	return start;
}

GenPoint Fluid::getEnd()
{
	return end;
}

int Fluid::getFillLine()
{
	return fillLine;
}

Color Fluid::getColor()
{
	Color colors;

	if (fluidName == "water")
	{
		colors.setColor(0, 0, 255);
		return colors;
	}
	else if (fluidName == "oil")
	{
		colors.setColor(142, 70, 70);
		return colors;
	}
	else
	{
		colors.setColor(255, 0, 255);
		return colors;
	}
}

string Fluid::getFluidName()
{
	return fluidName;
}