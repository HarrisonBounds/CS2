#include "RightTriangle.h"
#include "Triangle.h"
#include <iostream>
#include "graph1.h"

using namespace std;

RightTriangle::RightTriangle()
{
	a.setPoint(0, 0);
	b.setPoint(0, 0);
	c.setPoint(0, 0);
}

RightTriangle::RightTriangle(GenPoint vertex, int height, int base, Color color)
{
	a.setPoint(vertex.getX(), vertex.getY());
	b.setPoint(vertex.getX(), vertex.getY() - height);
	c.setPoint(vertex.getX() + base, vertex.getY());
	this->color = color;
}

void RightTriangle::print()
{
	Triangle::print();

	gout << setPos(0, 15) << "Right Triangle" << endg;

}