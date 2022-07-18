//Harrison Bounds
//Lab 10 In
//Draw Quadrilateral and Rectangle using Inheritance

#include <iostream>
#include "graph1.h"
#include "Quadrilateral.h"
#include "GenRectangle.h"

using namespace std;

int main()
{
    //Variable Declaration/Initialization
    int x = 0;
    int y = 0;
    int r = 0;
    int g = 0;
    int b = 0;
    char repeat = 'y';
    GenPoint p1;
    GenPoint p2;
    GenPoint p3;
    GenPoint p4;
    Color c;
    Quadrilateral quad;
    GenRectangle rect;

    //Display Graphics
    displayGraphics();

    //Run programs as many times as desired
    do
    {

        //Prompt for point #1
        cout << "Process Quadrilateral" << endl;
        cout << "Enter Point 1: ";
        cin >> x >> y;
        p1.setPoint(x, y);

        //Prompt for point #2
        cout << "Enter Point 2: ";
        cin >> x >> y;
        p2.setPoint(x, y);

        //Prompt for point #3
        cout << "Enter Point 3: ";
        cin >> x >> y;
        p3.setPoint(x, y);

        //Prompt for point #4
        cout << "Enter Point 4: ";
        cin >> x >> y;
        p4.setPoint(x, y);

        //Prompt for the color
        cout << "Enter Color: ";
        cin >> r >> g >> b;

        //Set all objects (including quad);
        c.setColor(r, g, b);
        quad.setCol(c);
        quad.setPoints(p1, p2, p3, p4);
        quad.draw();
        quad.print();

        cout << "Press y to Continue: ";
        cin >> repeat;

        //Clear graphics/console
        system("cls");
        clearGraphics();
        //--------------------------------------------------------------------------------

        //Prompt for rectangle points
        cout << "Process Rectangle " << endl;
        cout << "Enter upper left: ";
        cin >> x >> y;
        GenPoint ul(x, y);

        cout << "Enter lower right: ";
        cin >> x >> y;
        GenPoint lr(x, y);

        //Set the color
        rect.setCol(c);

        //Set the points for rectangle
        rect.setPoints(ul, lr);

        //Draw the rectangle
        rect.draw();

        //Display info
        rect.print();

        cout << "Repeat: (y/n): ";
        cin >> repeat;

    } while ((repeat == 'y') || (repeat == 'Y'));





    return 0;
}
