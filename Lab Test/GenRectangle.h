#pragma once
#ifndef GENRECTANGLE_H
#define GENRECTANGLE_H

class GenRectangle
{
private:
	int x;  //Upper left x coordinate for rectangle
	int y;  //Upper left y coordinate for rectangle
	int width;  //width of rectangle
	int height; //height of rectangle

public:
	GenRectangle(); //Default Construct- sets x to 100,y to 25,width to 20,height to 30
	int getWidth(); //Getter for width
	int getHeight(); //Getter for height
	int getX(); //Getter for x
	int getY(); //Getter for y
	int getArea();  //Returns the area of Rectangle
	int getPerimeter(); //Returns the perimeter of Rectangle
	void setWidth(int width);  //Setter for Width - Min 1 /Max 50
	void setHeight(int height); //Setter for Height - Min 1/ Max 50
	void setX(int x); //Setter for X - Min 100/ Max 539
	void setY(int y); //Setter for Y - Min 25/ Max 455
	string getType();
	void draw(); //Draws a hollow rectangle in the graphics window/Colors it based on rules
};

#endif
