//Harrison Bounds
//Lab Test 2
//Draw 2 Rectangles

#include <iostream>
#include "graph1.h"
#include "GenRectangle.h"

GenRectangle::GenRectangle()
{
	x = 100;
	y = 25;
	width = 20;
	height = 30;
}

int GenRectangle::getWidth()
{
	return width;
}

int GenRectangle::getHeight()
{
	return height;
}

int GenRectangle::getX()
{
	return x;
}

int GenRectangle::getY()
{
	return y;
}

int GenRectangle::getArea()
{
	int area = 0;

	area = width * height;

	return area;
}

int GenRectangle::getPerimeter()
{
	int perimeter = 0;

	perimeter = width * 2 + height * 2;

	return perimeter;
}

void GenRectangle::setWidth(int width)
{
	if (width > 50)
	{
		width = 50;
	}
	else if (width < 1)
	{
		width = 1;
	}
	else
	{
		this->width = width;
	}
}

void GenRectangle::setHeight(int height)
{
	if (height > 50)
	{
		height = 50;
	}
	else if (height < 1)
	{
		height = 1;
	}
	else
	{
		this->height = height;
	}
}

void GenRectangle::setX(int x)
{
	if (x > 539)
	{
		x = 539;
	}
	else if (x < 100)
	{
		x = 100;
	}
	else
	{
		this->x = x;
	}
}

void GenRectangle::setY(int y)
{
	if (y > 455)
	{
		y = 455;
	}
	else if (y < 25)
	{
		y = 25;
	}
	else
	{
		this->y = y;
	}
}

string GenRectangle::getType()
{

	int area = width * height;

	string type = "";

	if (area < 300)
	{
		type = "SMALL_RECTANGLE";
	}
	else if (area >= 300 && area < 1000)
	{
		type = "MIDDLE_RECTANGLE";
	}
	else if (area > 1000)
	{
		type = "LARGE_RECTANGLE";
	}

	return type;
}

void GenRectangle::draw()
{
	int area = width * height;
	int r, g, b = 0;

	if (area < 300)
	{
		r = 255;
		g = 0;
		b = 0;
	}
	else if (area >= 300 && area < 1000)
	{
		r = 0;
		g = 255;
		b = 0;
	}
	else if (area > 1000)
	{
		r = 0;
		g = 0;
		b = 255;
	}

	//Left Line
	setColor(drawLine(x, y, x, y + height, 1), r, g, b);

	//Bottom Line
	setColor(drawLine(x, y + height, x + width, y + height, 1), r, g, b);

	//Right Line
	setColor(drawLine(x + width, y + height, x + width, y, 1), r, g, b);

	//Top Line
	setColor(drawLine(x + width, y, x, y, 1), r, g, b);
}


