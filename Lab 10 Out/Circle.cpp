#include "Circle.h"
#include "Shape.h"
#include <iostream>
#include <cmath>
#include "graph1.h"

using namespace std;

Circle::Circle()
{
	radius = 0;
	center.setPoint(0, 0);
}

Circle::Circle(GenPoint center, int radius, Color c)
{
	this->center = center;
	this->radius = radius;
	this->color = c;
}

void Circle::setCenter(GenPoint center)
{
	this->center = center;
}

void Circle::setRadius(int radius)
{
	this->radius = radius;
}

double Circle::getPerimeter()
{
	//2pir
	double perimeter = 0.0;

	perimeter = 2 * 3.14 * radius;

	return perimeter;
}

double Circle::getArea()
{
	//pi * r^2
	double area = 0.0;

	area = 3.14 * pow(radius, 2);

	return area;
}

void Circle::print()
{
	gout << setPos(0, 400) << "---------------------------------------------------------"
		<< "----------------------------------------------------------------------------" << endg;
	gout << setPos(200, 405) << "Shape info Follows for: Circle" << endg;

	gout << setPos(200, 420) << "Center Point: (" << center.getX() << ", " << center.getY() << ")" << endg;
	gout << setPos(200, 435) << "Radius" << radius << endg;
	gout << setPos(200, 450) << "Perimeter: " << getPerimeter() << endg;
	
}

void Circle::draw()
{
	int circle = 0;

	circle = drawCircle(radius, center.getX(), center.getY());

	setColor(circle, color.getRed(), color.getGreen(), color.getBlue());
}