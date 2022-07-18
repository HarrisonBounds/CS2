#include <iostream>
#include "graph1.h"
#include "Simulation.h"
#include "Genpoint.h"
#include "Container.h"
#include "Color.h"


using namespace std;

const int FAUCET_WIDTH = 64;

int main()
{
    //Variable Declaration/Initialization
    int height = 0;
    int radius = 0;
    int fluid_rate = 0;
    int faucetx = 0;
    string fluidName = "";
    int r = 0;
    int b = 0;
    int g = 0;
    char repeat;
    Container container;
    Simulation simulation;
    Color colors;
    GenPoint position;
    GenPoint start;
    GenPoint end;
    GenPoint upper;
    Fluid fluid;
    Faucet faucet;

    //Display the graphics
    displayGraphics();

    //Continually simulate

    do
    {
        //Get the Container's fluid rate/radius/height/color/fluid name (Add Data Validation)
        do
        {
            cout << "Enter fluid rate between 1 and 30 gallons per minute: ";
            cin >> fluid_rate;
        } while (fluid_rate < 1 || fluid_rate > 30);

        do
        {
            cout << "What is the radius? <Between 10 and 285>: ";
            cin >> radius;
        } while (radius < 10 || radius > 285);

        do
        {
            cout << "What is the height? <Between 10 and 300>: ";
            cin >> height;
        } while (height < 10 || height > 300);

        do
        {
            cout << "What is the color? (RGB): ";
            cin >> r >> g >> b;
        } while (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 285);

        do
        {
            cout << "Enter fluid's name <water, oil, or diesel> (Lower Case): ";
            cin >> fluidName;
        } while (fluidName != "water" && fluidName != "oil" && fluidName != "diesel");
           
        //Build fluid objects
        fluid.setFluidName(fluidName);
        start.setPoint(50 + radius, 64);
        fluid.setStart(start);
        end.setPoint(50 + radius, 400);
        fluid.setEnd(end);
        fluid.setFillLine(400 - height);

        //Build Faucet objects
        faucet.setFluid(fluid);
        position.setPoint(radius - 4, 10);
        faucet.setPosition(position);

            
        
    
        //Color class
        colors.setColor(r, g, b);

        //Set the Containers radius/height/color
        container.setRadius(radius);

        container.setHeight(height);

        container.setCol(colors);


        //Compute the Container upper left coordinate based on the height

        //Set the Container’s position
        //Hint: 55, 400 - height
        position.setPoint(55, 400 - height);
        container.setPosition(position);

        //Set the Container, Faucet, and Fluid Rate for the Simulation
        simulation.setContainer(container);
        simulation.setFaucet(faucet);
        simulation.setWaterRate(fluid_rate);

        //Draw the simulation (invoke draw on Simulation)
        simulation.draw();

        //Start Simulation
        simulation.start();


        //Repeat the simulation?
        cout << "Repeat the simulation (y/n)? ";
        cin >> repeat;

        clearGraphics();
        system("cls");

    } while (repeat == 'y');

    return 0;
}
