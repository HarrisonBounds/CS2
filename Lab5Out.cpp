//Harrison Bounds
//Lab 5 Out
//Simulate a working clock

#include<iostream>
#include"graph1.h"

using namespace std;

const double PI = 3.14159;

class Clock
{
private:
    int hour;
    int min;
    int sec;


public:
    Clock();
    bool setHour(int h_val);
    int getHour();
    bool setMin(int m_val);
    int getMin();
    bool setSec(int s_val);
    int getSec();
    void draw();

};

Clock::Clock()
{
    //Set private data fields to default values
    hour = 0;
    min = 0;
    sec = 0;
}

bool Clock::setHour(int h_val)
{
    /*Check boundaries for hours
    If data entered is outside the boundaries
    set hour to min/max value depending*/

    bool result = true;

    if (h_val < 0)
    {
        hour = 0;
        result = false;
    }
    else if (h_val > 11)
    {
        hour = 11;
        result = false;
    }
    else
    {
        hour = h_val;
        result = true;
    }

    return result;
}

int Clock::getHour()
{
    return hour;
}

bool Clock::setMin(int m_val)
{
    /*Check boundaries for min
    If data entered is outside the boundaries
    set min to min/max value depending*/

    bool result = true;

    if (m_val < 0)
    {
        min = 0;
        result = false;
    }
    else if (m_val > 59)
    {
        min = 59;
        result = false;
    }
    else
    {
        min = m_val;
        result = true;
    }

    return result;
}

int Clock::getMin()
{
    return min;
}

bool Clock::setSec(int s_val)
{
    /*Check boundaries for sec
    If data entered is outside the boundaries
    set sec to min/max value depending*/

    bool result = true;

    if (s_val < 0)
    {
        sec = 0;
        result = false;
    }
    else if (s_val > 59)
    {
        sec = 59;
        result = false;
    }
    else
    {
        sec = s_val;
        result = true;
    }

    return result;
}

int Clock::getSec()
{
    return sec;
}

void Clock::draw()
{

    int x_center = 320;
    int y_center = 240;
    int sec_length = 150;
    int min_length = 180;
    int hour_length = 133;
    int x_sec_end = 0;
    int y_sec_end = 0;
    int x_min_end = 0;
    int y_min_end = 0;
    int x_hour_end = 0;
    int y_hour_end = 0;
    double alpha_sec = 0;
    double alpha_min = 0;
    double alpha_hour = 0;
    

    //Draw Clock
    displayPNG("clock_face.png", 123, 50);

    //Compute angle of hands
    alpha_sec = sec * 6.0;

    alpha_min = min * 6.0 + (sec / 60.0) * 6;

    alpha_hour = hour * 30.0 + (min / 60.0) * 30;


    //Get end points for Second hand

    //Quadrant 1
    if (alpha_sec >= 0 && alpha_sec < 90)
    {
        x_sec_end = x_center + (cos((90 - alpha_sec) * PI / 180.0)) * sec_length;
        y_sec_end = y_center - (sin((90 - alpha_sec) * PI / 180.0)) * sec_length;
    }

    //Quadrant 2
    else if (alpha_sec >= 90 && alpha_sec < 180)
    {
        x_sec_end = x_center + (cos((alpha_sec - 90) * PI / 180.0)) * sec_length;
        y_sec_end = y_center + (sin((alpha_sec - 90) * PI / 180.0)) * sec_length;
    }

    //Quadrant 3
    else if (alpha_sec >= 180 && alpha_sec < 270)
    {
        x_sec_end = x_center - (cos((270 - alpha_sec) * PI / 180.0)) * sec_length;
        y_sec_end = y_center + (sin((270 - alpha_sec) * PI / 180.0)) * sec_length;
    }

    //Quadrant 4
    else if (alpha_sec >= 270 && alpha_sec < 360)
    {
        x_sec_end = x_center - (cos((alpha_sec - 270) * PI / 180.0)) * sec_length;
        y_sec_end = y_center - (sin((alpha_sec - 270) * PI / 180.0)) * sec_length; 
    }

    //Get endpoint for Minute hand

    //Quadrant 1
    if (alpha_min >= 0 && alpha_min < 90)
    {
        x_min_end = x_center + (cos((90 - alpha_min) * PI / 180.0)) * min_length;
        y_min_end = y_center - (sin((90 - alpha_min) * PI / 180.0)) * min_length;
    }

    //Quadrant 2
    else if (alpha_min >= 90 && alpha_min < 180)
    {
        x_min_end = x_center + (cos((alpha_min - 90) * PI / 180.0)) * min_length;
        y_min_end = y_center + (sin((alpha_min - 90) * PI / 180.0)) * min_length;
    }

    //Quadrant 3
    else if (alpha_min >= 180 && alpha_min < 270)
    {
        x_min_end = x_center - (cos((270 - alpha_min) * PI / 180.0)) * min_length;
        y_min_end = y_center + (sin((270 - alpha_min) * PI / 180.0)) * min_length;
    }

    //Quadrant 4
    else if (alpha_min >= 270 && alpha_min < 360)
    {
        x_min_end = x_center - (cos((alpha_min - 270) * PI / 180.0)) * min_length;
        y_min_end = y_center - (sin((alpha_min - 270) * PI / 180.0)) * min_length;
    }

    //Get endpoint for Hour Hand

     //Quadrant 1
    if (alpha_hour >= 0 && alpha_hour < 90)
    {
        x_hour_end = x_center + (cos((90 - alpha_hour) * PI / 180.0)) * hour_length;
        y_hour_end = y_center - (sin((90 - alpha_hour) * PI / 180.0)) * hour_length;
    }

    //Quadrant 2
    else if (alpha_hour >= 90 && alpha_hour < 180)
    {
        x_hour_end = x_center + (cos((alpha_hour - 90) * PI / 180.0)) * hour_length;
        y_hour_end = y_center + (sin((alpha_hour - 90) * PI / 180.0)) * hour_length;
    }

    //Quadrant 3
    else if (alpha_hour >= 180 && alpha_hour < 270)
    {
        x_hour_end = x_center - (cos((270 - alpha_hour) * PI / 180.0)) * hour_length;
        y_hour_end = y_center + (sin((270 - alpha_hour) * PI / 180.0)) * hour_length;
    }

    //Quadrant 4
    else if (alpha_hour >= 270 && alpha_hour < 360)
    {
        x_hour_end = x_center - (cos((alpha_hour - 270) * PI / 180.0)) * hour_length;
        y_hour_end = y_center - (sin((alpha_hour - 270) * PI / 180.0)) * hour_length;
    }

    //Draw Second Hand

    setColor(drawLine(x_center, y_center, x_sec_end, y_sec_end, 1), 255, 0, 0);

    //Draw Min Hand

    setColor(drawLine(x_center, y_center, x_min_end, y_min_end, 2), 0, 0, 0);

    //Draw Hour Hand

    setColor(drawLine(x_center, y_center, x_hour_end, y_hour_end, 2), 0, 0, 0);

}


int main()
{
    int hour = 0;
    int min = 0;
    int sec = 0;

    char repeat;

    bool result = true;

    Clock clock1;

    displayGraphics();
    do
    {
        //Prompt user for data

        //Set values - display error message if data was outside range
        cout << "Enter the number of seconds: ";
        cin >> sec;

        result = clock1.setSec(sec);
        if (result == false)
        {
            cout << "Your number was outside the range - We have reset the number to a default value" << endl;
        }

        cout << "Enter the number of minutes: ";
        cin >> min;

        result = clock1.setMin(min);
        if (result == false)
        {
            cout << "Your number was outside the range - We have reset the number to a default value" << endl;
        }

        cout << "Enter the number of hours: ";
        cin >> hour;

        result = clock1.setHour(hour);
        if (result == false)
        {
            cout << "Your number was outside the range - We have reset the number to a default value" << endl;
        }

        clock1.draw();

        //Display time under the clock

        gout << setPos(280, 440) << "Time: " << clock1.getHour() << ":" << clock1.getMin() << ":"
            << clock1.getSec() << endg;

        //Prompt to repeat the program
        cout << "Would you like to repeat the program? <Y or y for Yes>: ";
        cin >> repeat;

        clearGraphics();
        system("cls");

    } while (repeat == 'Y' || repeat == 'y');
}






