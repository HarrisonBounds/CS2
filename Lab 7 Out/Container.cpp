#include <iostream>
#include <cmath>
#include "graph1.h"
#include "Container.h"
#include "GenPoint.h"
#include "Color.h"

Container::Container()
{
	pos.setPoint(0, 0);
	radius = 0;
	height = 0;
	color.setColor(0, 0, 0);
}

void Container::setPosition(GenPoint pos)
{
	this->pos.setPoint(pos.getX(), pos.getY());
}

void Container::setRadius(int radius)
{
	this->radius = radius;
}
void Container::setHeight(int height)
{
	this->height = height;
}

void Container::setCol(Color color)
{
	this->color = color;
}

GenPoint Container::getPosition()
{
	return pos;
}

int Container::getRadius()
{
	return radius;
}

int Container::getHeight()
{
	return height;
}

Color Container::getColor()
{
	return color;
}

void Container::draw()
{
	//Line 1 (Closest to the wall)
	// |
	// |
	// |
	// |

	int line1 = 0;
	int line2 = 0;
	int line3 = 0;

	line1 = drawLine(pos.getX(), pos.getY(), pos.getX(), pos.getY() + height, 5);
	setColor(line1, color.getRed(), color.getGreen(), color.getBlue());

	//Line 2 (Bottom Line)
	// ----------------------

    line2 = drawLine(pos.getX(), pos.getY() + height, pos.getX() + (radius * 2), pos.getY() + height, 5);
	setColor(line2, color.getRed(), color.getGreen(), color.getBlue());

	//Line 3 (right side)
	//					|
	//					|
	//					|
	//					|
	//					|

	line3 = drawLine(pos.getX() + (radius * 2), pos.getY() + height, pos.getX() + (radius * 2), pos.getY(), 5);
	setColor(line3, color.getRed(), color.getGreen(), color.getBlue());
	
}

