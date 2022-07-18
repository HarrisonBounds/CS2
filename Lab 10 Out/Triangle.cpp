#include "Triangle.h"
#include "Shape.h"
#include <iostream>
#include <cmath>
#include "graph1.h"

using namespace std;

Triangle::Triangle()
{
	a.setPoint(0, 0);
	b.setPoint(0, 0);
	c.setPoint(0, 0);
}

Triangle::Triangle(GenPoint a, GenPoint b, GenPoint c, Color color)
{
	this->a = a;
	this->b = b;
	this->c = c;

	this->color = color;
}

void Triangle::setPoints(GenPoint a, GenPoint b, GenPoint c)
{
	this->a.setPoint(a.getX(), a.getY());
	this->b.setPoint(b.getX(), b.getY());
	this->c.setPoint(c.getX(), c.getY());
}

double Triangle::getArea()
{
	//.5 * base * height
	double area = 0.0;

	double base = sqrt(pow(c.getX() - a.getX(), 2) + pow(c.getY() - a.getY(), 2));
	double height = sqrt(pow(b.getX() - a.getX(), 2) + pow(b.getY() - a.getY(), 2));

	area = 0.5 * base * height;

	return area;
}

double Triangle::getPerimeter()
{
	double perimeter = 0.0;
	double AB = sqrt(pow(b.getX() - a.getX(), 2) + pow(b.getY() - a.getY(), 2));
	double BC = sqrt(pow(c.getX() - b.getX(), 2) + pow(c.getY() - b.getY(), 2));
	double CA = sqrt(pow(c.getX() - a.getX(), 2) + pow(c.getY() - a.getY(), 2));

	perimeter = AB + BC + CA;

	return perimeter;
}

void Triangle::print()
{
	gout << setPos(0, 400) << "---------------------------------------------------------"
		<< "----------------------------------------------------------------------------" << endg;
	gout << setPos(200, 405) << "Shape info Follows for: Triangle" << endg;

	gout << setPos(200, 420) << "Point a (" << a.getX() << ", " << a.getY() << ")" << endg;
	gout << setPos(200, 435) << "Point b (" << b.getX() << ", " << b.getY() << ")" << endg;
	gout << setPos(200, 450) << "Point c (" << c.getX() << ", " << c.getY() << ")" << endg;
	gout << setPos(200, 480) << "Perimeter:" << getPerimeter() << "   Area: " << getArea() << endg;
}

void Triangle::draw()
{
	//Draw Triangle
	int lineAB;
	int lineBC;
	int lineCA;

	//Draw Line
	lineAB = drawLine(a.getX(), a.getY(), b.getX(), b.getY(), 2);
	lineBC = drawLine(b.getX(), b.getY(), c.getX(), c.getY(), 2);
	lineCA = drawLine(c.getX(), c.getY(), a.getX(), a.getY(), 2);
	
	//Color Lines
	setColor(lineAB, color.getRed(), color.getGreen(), color.getBlue());
	setColor(lineBC, color.getRed(), color.getGreen(), color.getBlue());
	setColor(lineCA, color.getRed(), color.getGreen(), color.getBlue());
	

}