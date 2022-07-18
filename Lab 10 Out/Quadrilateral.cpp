#include<iostream>
#include "Quadrilateral.h"
#include "graph1.h"
#include <cmath>
#include "Color.h"
#include "Shape.h"

using namespace std;

Quadrilateral::Quadrilateral()
{
	a.setPoint(0, 0);
	b.setPoint(0, 0);
	c.setPoint(0, 0);
	d.setPoint(0, 0);

	color.setCol(0, 0, 0);
}

Quadrilateral::Quadrilateral(GenPoint a, GenPoint b, GenPoint c, GenPoint d, Color color)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;

	//Assign quadrilateral color
	this->color = color;

}

void Quadrilateral::setPoints(GenPoint a, GenPoint b, GenPoint c, GenPoint d)
{
	//Clip x and y values for a
	if (a.getX() < 0)
	{
		this->a.setPoint(0, a.getY());
	}

	else if (a.getX() > 639)
	{
		this->a.setPoint(639, a.getY());
	}

	else if (a.getY() < 0)
	{
		this->a.setPoint(a.getX(), 0);
	}
	
	else if (a.getY() > 399)
	{
		this->a.setPoint(a.getX(), 399);
	}
	else
	{
		this->a = a;
	}

	//Clip x and y values for b
	if (b.getX() < 0)
	{
		this->b.setPoint(0, b.getY());
	}

	else if (b.getX() > 639)
	{
		this->b.setPoint(639, b.getY());
	}

	else if (b.getY() < 0)
	{
		this->b.setPoint(b.getX(), 0);
	}

	else if (b.getY() > 399)
	{
		this->b.setPoint(b.getX(), 399);
	}
	else
	{
		this->b = b;
	}

	//Clip x and y values for c
	if (c.getX() < 0)
	{
		this->c.setPoint(0, c.getY());
	}

	else if (c.getX() > 639)
	{
		this->c.setPoint(639, c.getY());
	}

	else if (c.getY() < 0)
	{
		this->c.setPoint(c.getX(), 0);
	}

	else if (c.getY() > 399)
	{
		this->c.setPoint(c.getX(), 399);
	}
	else
	{
		this->c = c;
	}

	//Clip x and y values for d
	if (d.getX() < 0)
	{
		this->d.setPoint(0, d.getY());
	}

	else if (d.getX() > 639)
	{
		this->d.setPoint(639, d.getY());
	}

	else if (d.getY() < 0)
	{
		this->d.setPoint(d.getX(), 0);
	}

	else if (d.getY() > 399)
	{
		this->d.setPoint(d.getX(), 399);
	}
	else
	{
		this->d = d;
	}

	
}

double Quadrilateral::getPerimeter()
{
	double perimeter = 0.0;
	double AB = 0.0;
	double BC = 0.0;
	double CD = 0.0;
	double DA = 0.0;

	//Find the distance between points
	AB = sqrt(pow(b.getX() - a.getX(), 2) + pow(b.getY() - a.getY(), 2));
	BC = sqrt(pow(c.getX() - b.getX(), 2) + pow(c.getY() - b.getY(), 2));
	CD = sqrt(pow(d.getX() - c.getX(), 2) + pow(d.getY() - c.getY(), 2));
	DA = sqrt(pow(a.getX() - d.getX(), 2) + pow(a.getY() - d.getY(), 2));

	perimeter = AB + BC + CD + DA;

	return perimeter;
}

void Quadrilateral::print()
{
	gout << setPos(0, 400) << "---------------------------------------------------------"
		<< "----------------------------------------------------------------------------" << endg;
	gout << setPos(200, 405) << "Shape info Follows for: Quadrilateral" << endg;

	gout << setPos(200, 420) << "Point a (" << a.getX() << ", " << a.getY() << ")" << endg;
	gout << setPos(200, 435) << "Point b (" << b.getX() << ", " << b.getY() << ")" << endg;
	gout << setPos(200, 450) << "Point c (" << c.getX() << ", " << c.getY() << ")" << endg;
	gout << setPos(200, 465) << "Point d (" << d.getX() << ", " << d.getY() << ")" << endg;
	gout << setPos(200, 480) << "Perimeter:" << getPerimeter() << endg;
}

void Quadrilateral::draw()
{
	

	//Draw and Color Lines
	setColor(drawLine(a.getX(), a.getY(), b.getX(), b.getY(), 2), color.getRed(), color.getGreen(), color.getBlue());
	setColor(drawLine(b.getX(), b.getY(), c.getX(), c.getY(), 2), color.getRed(), color.getGreen(), color.getBlue());
	setColor(drawLine(c.getX(), c.getY(), d.getX(), d.getY(), 2), color.getRed(), color.getGreen(), color.getBlue());
	setColor(drawLine(d.getX(), d.getY(), a.getX(), a.getY(), 2), color.getRed(), color.getGreen(), color.getBlue());

	
	
}

