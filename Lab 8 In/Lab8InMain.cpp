//Harrison Bounds
//Lab 8 In
//Overload several basic operators

#include <iostream>
#include "graph1.h"
#include "Lab8InColor.h"

using namespace std;

int main()
{
    //Variable Declaration/Initialization
    int choice = 0;
    int r = 0;
    int g = 0;
    int b = 0;
    int scale_factor = 0;
    Color c1;
    Color c2;
    Color result1;
    bool result3;
    char repeat = 'y';
    string operators[] = { "+","-","==","!=","*","/","!" };

    //Display graphics window
    displayGraphics();

    //Repeat as many times as desired
    do
    {


        //Display menu
        cout << "1. Add Colors" << endl;
        cout << "2. Sub Colors" << endl;
        cout << "3. Compare Two Colors (Equality)" << endl;
        cout << "4. Compare Two Colors (Inequality) " << endl;
        cout << "5. Multiply Color by Scalar" << endl;
        cout << "6. Divide Color by Scalar" << endl;
        cout << "7. Invert Color" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        //Always Prompt for one colors 
        //Prompt for color #1
        cout << "Enter Color #1: ";
        cin >> r >> g >> b;
        c1.setCol(r, g, b);

        //Prompt for color #2 (if choice is 1,2,3,4
        if ((choice == 1) || (choice == 2) || (choice == 3) || (choice == 4))
        {
            cout << "Enter Color #2: ";
            cin >> r >> g >> b;
            c2.setCol(r, g, b);


        }
        //Prompt for scalar if choice is 5,6
        else if ((choice == 5) || (choice == 6))
        {
            cout << "Enter scale factor: ";
            cin >> scale_factor;
        }


        //Process choice
        switch (choice)
        {
        case 1:
            //Add results
            result1 = c1 + c2;
            break;

        case 2:
            //subtract results
            result1 = c1 - c2;
            break;

        case 3:
            //Compare 2 results (equality)
            result3 = (c1 == c2);
            break;

        case 4:
            //Compare 2 results (inequality)
            result3 = (c1 != c2);
            break;

        case 5:
            //Multiply by scalar
            result1 = c1 * scale_factor;
            break;

        case 6:
            //Divide by scalar
            result1 = c1 / scale_factor;
            break;

        case 7:
            //Invert Color
            result1 = !c1;
            break;

        default:
            //Display error message
            cout << "Incorrect choice" << endl;

        }

        //Display title for results
        gout << setPos(200, 50) << "Results for choice " << operators[choice - 1] << endg;

        //Display Results in Graphics Window
        if ((choice == 1) || (choice == 2) || (choice == 3) || (choice == 4))
        {

            //Draw Color 1
            c1.draw(200, 100, 50, 50);
            gout << setPos(200, 75) << "Color #1" << endg;

            //Draw the operator
            gout << setPos(275, 125) << operators[choice - 1] << endg;

            //Draw Color 2
            c2.draw(300, 100, 50, 50);
            gout << setPos(300, 90) << "Color #2" << endg;

            //Draw the assignment operator
            gout << setPos(175, 125) << "=" << endg;

            if ((choice == 1) || (choice == 2))
            {
                //Draw Color Result (1/2)
                result1.draw(100, 100, 50, 50);
                gout << setPos(100, 90) << "Result" << endg;
            }
            else if ((choice == 3) || (choice == 4))
            {
                //Display equality
                gout << setPos(100, 125) << result3 << endg;
            }
        }
        else if ((choice == 5) || (choice == 6))
        {
            //Draw Color 1
            c1.draw(200, 100, 50, 50);
            gout << setPos(200, 90) << "Color #1" << endg;

            //display the operator
            gout << setPos(275, 125) << operators[choice - 1] << endg;


            //display the scale factor
            gout << setPos(325, 125) << scale_factor << endg;

            //Draw the assignment operator
            gout << setPos(175, 125) << "=" << endg;

            //Draw Color Result
            result1.draw(100, 100, 50, 50);
            gout << setPos(100, 90) << "Result" << endg;

        }
        else if (choice == 7)
        {
            //Draw Color 1
            c1.draw(200, 100, 50, 50);
            gout << setPos(200, 90) << "Color #1" << endg;

            //display the operator
            gout << setPos(195, 125) << operators[choice - 1] << endg;

            //Draw the assignment operator
            gout << setPos(175, 125) << "=" << endg;

            //Draw Color Result
            result1.draw(100, 100, 50, 50);
            gout << setPos(100, 90) << "Result" << endg;
        }

        //Repeat?
        cout << "Repeat Program (y/n)? ";
        cin >> repeat;

        system("cls");
        clearGraphics();

    } while ((repeat == 'y') || (repeat == 'Y'));

    return 0;
}

