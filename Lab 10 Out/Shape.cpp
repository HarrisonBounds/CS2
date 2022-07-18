
#include "Shape.h"
#include <iostream>

using namespace std;

Shape::Shape()
{
	color.setCol(0, 0, 0);
}

Color Shape::getColor()
{
	return color;
}

void Shape::setCol(Color color)
{
	this->color.setCol(color.getRed(), color.getGreen(), color.getBlue());
}



