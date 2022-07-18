#include <iostream>
#include "graph1.h"
#include "Lab8InColor.h"

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
void Color::setCol(int r, int g, int b)
{
	//Set Red
	if (r < 0)
	{
		r = 0;
	}
	else if (r > 255)
	{
		r = 255;
	}
	else
	{
		this->r = r;
	}

	//Set Green
	if (g < 0)
	{
		g = 0;
	}
	else if (g > 255)
	{
		g = 255;
	}
	else
	{
		this->g = g;
	}

	//Set Blue
	if (b < 0)
	{
		b = 0;
	}
	else if (b > 255)
	{
		b = 255;
	}
	else
	{
		this->b = b;
	}

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
Color Color::operator+(Color right)
{
	Color result;

	result.r = r + right.getRed();
	if (result.r > 255)
	{
		result.r = 255;
	}

	result.g = g + right.getGreen();
	if (result.g > 255)
	{
		result.g = 255;
	}

	result.b = b + right.getBlue();
	if (result.b > 255)
	{
		result.b = 255;
	}

	return result;

}
Color Color::operator-(Color right)
{
	Color result;

	result.r = r - right.getRed();
	if (result.r < 0)
	{
		result.r = 0;
	}
	result.g = g - right.getGreen();
	if (result.g < 0)
	{
		result.g = 0;
	}
	result.b = b - right.getBlue();
	if (result.b < 0)
	{
		result.b = 0;
	}

	return result;
}
Color Color::operator/(int right)
{
	Color result;

	//Dont have to clip because divinding a + / + = +
	result.r = r / right;
	
	result.g = g - right;
	
	result.b = b - right;
	

	return result;


}
Color Color::operator*(int right)
{
	Color result;

	result.r = r * right;
	if (result.r > 255)
	{
		result.r = 255;
	}

	result.g = g + right;
	if (result.g > 255)
	{
		result.g = 255;
	}

	result.b = b + right;
	if (result.b > 255)
	{
		result.b = 255;
	}

	return result;
}
bool Color::operator==(Color right)
{
	//Create an initial bool value
	bool result = false;

	//check if the values are not equal to each other
	if (r != right.r)
	{
		return result;
	}
	else
	{
		result = true;
		return result;
	}


	if (g != right.g)
	{
		return result;
	}
	else
	{
		result = true;
		return result;
	}

	if (b != right.b)
	{
		return result;
	}
	else
	{
		result = true;
		return result;
	}
}
bool Color::operator!=(Color right)
{
	//Create an initial bool value
	bool result = true;

	//check if the values are not equal to each other
	if (r != right.r)
	{
		return result;
	}
	else
	{
		result = false;
		return result;
	}


	if (g != right.g)
	{
		return result;
	}
	else
	{
		result = false;
		return result;
	}

	if (b != right.b)
	{
		return result;
	}
	else
	{
		result = false;
		return result;
	}
}
void Color::operator=(Color right)
{
	r = right.r;
	g = right.g;
	b = right.b;
}
Color Color::operator!()
{
	Color result;

	result.r = 255 - r;
	result.g = 255 - g;
	result.b = 255 - b;

	return result;
}
void Color::draw(int x, int y, int w, int h)
{
	setColor(drawRect(x, y, w, h), r, g, b);
}

