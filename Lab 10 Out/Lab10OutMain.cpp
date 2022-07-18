//Harrison Bounds
//Lab 10 Out
//Draw Shapes using Inheritance

#include <iostream>
#include "graph1.h"
#include "Circle.h"
#include "Shape.h"
#include "Color.h"
#include "GenPoint.h"
#include "Quadrilateral.h"
#include "GenRectangle.h"
#include "RightTriangle.h"
#include "Trapezoid.h"
#include "Triangle.h"

int main()
{
    //Variable Declaration
    int x = 0;
    int y = 0;
    int r = 0;
    int g = 0;
    int b = 0;
    int choice = 0;
    int radius = 0;
    int base = 0;
    int height = 0;
    char repeat = 'y';
    Shape* shape = NULL;
    GenPoint a1;
    GenPoint b1;
    GenPoint c1;
    GenPoint d1;
    Color color;

    //Display graphics
    displayGraphics();

    //Repeat program as many times as desired
    do
    {

        //Display the menu
        cout << "1. Circle" << endl;
        cout << "2. Quadrilateral" << endl;
        cout << "3. Rectangle" << endl;
        cout << "4. Trapezoid" << endl;
        cout << "5. Triangle" << endl;
        cout << "6. Right Triangle" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        //Enter Color
        cout << "\nEnter Color For Object: ";
        cin >> r >> g >> b;
        color.setCol(r, g, b);

        switch (choice)
        {
        case 1:
            //Process Circle info
            cout << "Enter radius: ";
            cin >> radius;

            cout << "Enter Center x/y coordinate: ";
            cin >> x >> y;

            //Create circle
            shape = new Circle(GenPoint(x, y), radius, color);
            break;

        case 2:
            //Process Quadrilateral Info
            cout << "Enter Point a: ";
            cin >> x >> y;
            a1.setPoint(x, y);

            cout << "Enter Point b: ";
            cin >> x >> y;
            b1.setPoint(x, y);

            cout << "Enter Point c: ";
            cin >> x >> y;
            c1.setPoint(x, y);

            cout << "Enter Point d: ";
            cin >> x >> y;
            d1.setPoint(x, y);

            shape = new Quadrilateral(a1, b1, c1, d1, color);
            break;

        case 3:
            //Process Rectangle info
            cout << "Enter upper left: ";
            cin >> x >> y;
            a1.setPoint(x, y);

            cout << "Enter lower right: ";
            cin >> x >> y;
            b1.setPoint(x, y);

            shape = new GenRectangle(a1, b1, color);
            break;

        case 4:
            //Process Trapezoid info
            cout << "Enter Point a: ";
            cin >> x >> y;
            a1.setPoint(x, y);

            cout << "Enter Point b: ";
            cin >> x >> y;
            b1.setPoint(x, y);

            cout << "Enter Point c: ";
            cin >> x >> y;
            c1.setPoint(x, y);

            cout << "Enter Point d: ";
            cin >> x >> y;
            d1.setPoint(x, y);

            shape = new Trapezoid(a1, b1, c1, d1, color);
            break;

        case  5:
            //Process Triangle Info
            cout << "Enter Point a: ";
            cin >> x >> y;
            a1.setPoint(x, y);

            cout << "Enter Point b: ";
            cin >> x >> y;
            b1.setPoint(x, y);

            cout << "Enter Point c: ";
            cin >> x >> y;
            c1.setPoint(x, y);

            shape = new Triangle(a1, b1, c1, color);
            break;

        case 6:
            //Process Right Triangle Info
            cout << "Enter base width: ";
            cin >> base;

            cout << "Enter base height: ";
            cin >> height;

            cout << "Enter vertex coordinates: ";
            cin >> x >> y;
            a1.setPoint(x, y);

            shape = new RightTriangle(a1, height, base, color);
            break;

        default:
            break;
        }

        //Process the shape info
        shape->print();
        shape->draw();

        //Repeat program?
        cout << "Repeat program? (y/n): ";
        cin >> repeat;

        //Clear console/graphics
        system("cls");
        clearGraphics();

    } while ((repeat == 'y') || (repeat == 'Y'));


    return 0;
}


