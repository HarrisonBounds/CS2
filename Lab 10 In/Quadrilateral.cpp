#include<iostream>
#include "Quadrilateral.h"
#include "graph1.h"
#include <cmath>

using namespace std;

Quadrilateral::Quadrilateral()
{
	a.setPoint(0, 0);
	b.setPoint(0, 0);
	c.setPoint(0, 0);
	d.setPoint(0, 0);

	color.setColor(0, 0, 0);
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

void Quadrilateral::setCol(Color color)
{
	this->color = color;
}

double Quadrilateral::getPerimeter()//??
{
	double perimeter = 0.0;
	double AB = 0.0;
	double BC = 0.0;
	double CD = 0.0;
	double DA = 0.0;

	//Find the distance between points
	AB = pow(b.getX() - a.getX(), 2) + pow(b.getY() - a.getY(), 2);
	BC = pow(c.getX() - b.getX(), 2) + pow(c.getY() - b.getY(), 2);
	CD = pow(d.getX() - c.getX(), 2) + pow(d.getY() - c.getY(), 2);
	DA = pow(a.getX() - d.getX(), 2) + pow(a.getY() - d.getY(), 2);

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
}

void Quadrilateral::draw()
{
	//Draw Quadrilateral
	int lineAB;
	int lineBC;
	int lineCD;
	int lineDA;

	//Draw Line
	lineAB = drawLine(a.getX(), a.getY(), b.getX(), b.getY(), 2);
	lineBC = drawLine(b.getX(), b.getY(), c.getX(), c.getY(), 2);
	lineCD = drawLine(c.getX(), c.getY(), d.getX(), d.getY(), 2);
	lineDA = drawLine(d.getX(), d.getY(), a.getX(), a.getY(), 2);

	//Color Line
	setColor(lineAB, color.getRed(), color.getGreen(), color.getBlue());
	setColor(lineBC, color.getRed(), color.getGreen(), color.getBlue());
	setColor(lineCD, color.getRed(), color.getGreen(), color.getBlue());
	setColor(lineDA, color.getRed(), color.getGreen(), color.getBlue());
}

