#include <iostream>
#include <cmath>
#include "Color.h" 
#include "graph1.h" 

Color::Color()
{
	r = 0;
	g = 0;
	b = 0;
}

Color::Color(int r, int g, int b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}


void Color::setColor(int r, int g, int b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}

int Color::getRed()
{
	return r;
}

int Color::getGreen()
{
	return g;
}

int Color::getBlue()
{
	return b;
}
