#include "Trapezoid.h"
#include "Quadrilateral.h"
#include "Shape.h"
#include <iostream>
#include <cmath>
#include "graph1.h"

using namespace std;

Trapezoid::Trapezoid()
{
	a.setPoint(0, 0);
	b.setPoint(0, 0);
	c.setPoint(0, 0);
	d.setPoint(0, 0);
}

Trapezoid::Trapezoid(GenPoint a, GenPoint b, GenPoint c, GenPoint d, Color color)
{
	this->a.setPoint(a.getX(), a.getY());
	this->b.setPoint(b.getX(), b.getY());
	this->c.setPoint(c.getX(), c.getY());
	this->d.setPoint(d.getX(), d.getY());
	this->color = color;


}

void Trapezoid::setPoints(GenPoint a, GenPoint b, GenPoint c, GenPoint d)
{
	this->a.setPoint(a.getX(), a.getY());
	this->b.setPoint(b.getX(), b.getY());
	this->c.setPoint(c.getX(), c.getY());
	this->d.setPoint(d.getX(), d.getY());
}

double Trapezoid::getArea()
{
	int area = 0;

	int A = b.getX() - a.getX();
	int B = c.getX() - d.getX();
	int height = a.getY() - d.getY();

	area = ((A + B) / 2)* height;
	
	return area;
}

void Trapezoid::print()
{

	gout << setPos(0, 15) << "Traperzoid Information" << endg;
	gout << setPos(0, 30) << "Area: " << getArea() << endg;

	Quadrilateral::print();
}