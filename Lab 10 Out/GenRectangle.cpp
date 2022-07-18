#include<iostream>
#include "GenRectangle.h"
#include "graph1.h"
#include <cmath>
#include "Shape.h"

using namespace std;

GenRectangle::GenRectangle()
{
	cout << "GenRectangle Class";
}

GenRectangle::GenRectangle(GenPoint ul, GenPoint lr, Color c)
{
	a.setPoint(ul.getX(), ul.getY());
	b.setPoint(lr.getX(), ul.getY());
	this->c.setPoint(lr.getX(), lr.getY());
	d.setPoint(ul.getX(), lr.getY());
	color = c;

}

void GenRectangle::setPoints(GenPoint ul, GenPoint lr)
{
	a.setPoint(ul.getX(), ul.getY());
	b.setPoint(lr.getX(), ul.getY());
	c.setPoint(lr.getX(), lr.getY());
	d.setPoint(ul.getX(), lr.getY());


	//Reset points for the quadrilateral
	Quadrilateral::setPoints(a, b, c, d);
}

double GenRectangle::getArea()
{
	int area = 0.0;
	int length = 0;
	int width = 0;

	length = d.getY() - a.getY();
	width = b.getX() - a.getX();

	area = length * width;

	return area;
}

void GenRectangle::print()
{
	
	gout << setPos(100, 10) << "Rectangle Information" << endg;
	gout << setPos(100, 25) << "Area: " << getArea() << endg;

	Quadrilateral::print();
}