//Harrison Bounds
//Lab Test 2
//Draw 2 Rectangles

#include <iostream>
#include "graph1.h"
#include "GenRectangle.h"

using namespace std;

int main()
{
	//Variable Declaration
	GenRectangle rect1;
	GenRectangle rect2;
	int offset = 15;
	int area = 0;
	int x = 0;
	int y = 0;
	int width = 0;
	int height = 0;
	char repeat;

	//Display Graphics
	displayGraphics();

	do
	{
		//Draw rect1
		rect1.draw();

		gout << setPos(rect1.getX(), rect1.getY() + rect1.getHeight() + offset) << "rect1" << endg;
		gout << setPos(rect1.getX(), rect1.getY() + rect1.getHeight() + (offset * 2)) << "Area: "
			<< rect1.getArea() << endg;
		gout << setPos(rect1.getX(), rect1.getY() + rect1.getHeight() + (offset * 3)) << "Perimeter: "
			<< rect1.getPerimeter() << endg;
		gout << setPos(rect1.getX(), rect1.getY() + rect1.getHeight() + (offset * 4)) << "Type: "
			<< rect1.getType() << endg;

		//Prompt for rect 2

		cout << "Enter x/y coordinate: ";
		cin >> x >> y;

		cout << "Enter width for the rectangle: ";
		cin >> width;

		cout << "Enter height for rectangle: ";
		cin >> height;

		//Invoke setter for prompted values

		rect2.setX(x);
		rect2.setY(y);
		rect2.setWidth(width);
		rect2.setHeight(height);

		//Draw rect2
		rect2.draw();

		gout << setPos(rect2.getX(), rect2.getY() + rect2.getHeight() + offset) << "rect2" << endg;
		gout << setPos(rect2.getX(), rect2.getY() + rect2.getHeight() + (offset * 2)) << "Area: "
			<< rect2.getArea() << endg;
		gout << setPos(rect2.getX(), rect2.getY() + rect2.getHeight() + (offset * 3)) << "Perimeter: "
			<< rect2.getPerimeter() << endg;
		gout << setPos(rect2.getX(), rect2.getY() + rect2.getHeight() + (offset * 4)) << "Type: "
			<< rect2.getType() << endg;

		//Repeat
		cout << "Wouuld you like to repeat the program? <Y or y for yes>: \n";
		cin >> repeat;

		clearGraphics();
		system("cls");

	} while (repeat == 'Y' || repeat == 'y');


}