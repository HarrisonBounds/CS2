//Harrison Bounds
//Declare a class pertaining to a circle
//Lab 5 In

#include <iostream>
#include "graph1.h"

using namespace std;

class FilledCircle
{
private:
	int x;
	int y;
	int radius;

public:
	FilledCircle();
	bool setX(int x_val);
	int getX();
	bool setY(int y_val);
	int getY();
	bool setRadius(int r_val);
	int getRadius();
	void draw();
};

FilledCircle::FilledCircle()
{
    //Set private data fields to default values
    x = 0;
    y = 0;
    radius = 15;
}


bool FilledCircle::setX(int x_val)
{
    bool result = true;
    //Implement rules for x_val when out of range  
    if (x_val <= 0)
    {
        x = 0;
        result = false;
    }
    else if (x_val >= 640)
    {
        x = 639;
        result = false;
    }
    else
    {
        x = x_val;
        result = true;
    }

    return result;
}

int FilledCircle::getX()
{
    return x;
}

bool FilledCircle::setY(int y_val)
{
    bool result = true;
    //Implement rules for setting the y-coord
    if (y_val <= 0)
    {
        y = 0;
        result = false;
    }
    else if (y_val >= 480)
    {
        y = 479;
        result = false;
    }
    else
    {
        y = y_val;
        result = true;
    }

    return result;
}

int FilledCircle::getY()
{
    return y;
}

bool FilledCircle::setRadius(int r_val)
{
    //Implement rule for setting the radius
    bool result = true;
    if (r_val <= 0)
    {
        radius = 1;
        result = false;
    }
    else if (r_val > 30)
    {
        radius = 30;
        result = false;
    }
    else
    {
        radius = r_val;
        result = true;
    }

    return result;
}

int FilledCircle::getRadius()
{
    return radius;
}

void FilledCircle::draw()
{
    //Draw the filled circle
    for (int i = 0; i < radius; i++)
    {
        drawCircle(i, x, y);
    }
}

int main()
{
    //Variable Declaration/Initialization
    int i = 0;
    int x = 0;
    int y = 0;
    int radius = 0;

    FilledCircle circle1;
    bool result = true;
    char repeat;

    //Display the Graphics
    displayGraphics();

    do
    {
        //Prompt for the x/y coordinates
        cout << "Enter x/y coords: ";
        cin >> x >> y;

        //Prompt for the radius
        cout << "Enter radius: ";
        cin >> radius;

        //Set the x coord for circle1 – display message if x is out of range
        result = circle1.setX(x);
        if (result == false)
        {
            cout << "ERROR - x is outside the range. ";
        }

        //Set the y coord for circle1 – display message if y is out of range
        result = circle1.setY(y);
        if (result == false)
        {
            cout << "ERROR - y is outside the range. ";
        }



        //Set the radius for cirle1 – display message if radius is out of range
        result = circle1.setRadius(radius);
        if (result == false)
        {
            cout << "ERROR - radius is outside the range. ";
        }

        //Draw the circle
        circle1.draw();

        //Display the coordinate info, radius info under the circle along with the 

        //Use the gout
        //To access the values of x, y, and radius you need 
        //to use getters

        gout << "(" << circle1.getX() << ", " << circle1.getY() << ")"
            << setPos(circle1.getX() - circle1.getRadius() - 5, circle1.getY() + (circle1.getRadius() + 15)) << endg;

        gout << "Radius: " << circle1.getRadius() << setPos(circle1.getX() - circle1.getRadius() - 5, circle1.getY() + (circle1.getRadius() + 30)) << endg;


        cout << "\nWould you like to repeat? (y/n): ";
        cin >> repeat;

        clearGraphics();
        system("cls");

    } while (repeat == 'Y' || repeat == 'y');
}
