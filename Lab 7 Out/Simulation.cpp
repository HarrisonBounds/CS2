#include <iostream>
#include "graph1.h"
#include "Simulation.h"
#include "Container.h"

using namespace std;

Simulation::Simulation()
{
	setContainer(container);
	setFaucet(faucet);
	int waterRate = 0;
}

void Simulation::setContainer(Container container)
{
	this->container = container;
}

Container Simulation::getContainer()
{
	return container;
}

void Simulation::setFaucet(Faucet faucet)
{
	this->faucet = faucet;
}

Faucet Simulation::getFaucet()
{
	return faucet;
}

int Simulation::getWaterRate()
{
	return waterRate;
}

void Simulation::setWaterRate(int waterRate)
{
	this->waterRate = waterRate;
}

void Simulation::draw()
{
	GenPoint upper;
	upper.setPoint((container.getRadius() - 60) + 50, 10);

	//Draw a wall
	setColor(drawRect(0, 0, 55, 400), 200, 200, 200);

	//Draw the ground using drawRect
	setColor(drawRect(0, 400, 640, 80), 71, 35, 35);

	//Set faucet position
	faucet.setPosition(upper);

	//Draw Pipe
	setColor(drawLine(55, 50, container.getRadius() + 50, 50, 5), 80, 80, 80);

	//Draw Faucet
	faucet.draw();
}

void Simulation::start()
{
	double delta_h = 0;
	double new_water_rate = 0;
	int x = 56;
	double y = container.getPosition().getY();
	y += container.getHeight();

	//Draw Faucet
	faucet.draw();

	//Draw Container
	container.draw();

	//Turn on Faucet
	faucet.turnOn();

	//Change water rate from gallons per minute to mm cubed per second
	new_water_rate = (3785411.78 * getWaterRate()) / 60;

	//Calculate delta h
	delta_h = new_water_rate / (3.14 * container.getRadius() * container.getRadius());

	

	if (delta_h >= 16)
	{
		delta_h = 15.7;
	}
	else if (delta_h < 1)
	{
		delta_h = 1;
	}
	
	y -= delta_h;

	//Make the fluid rise in the container
	for (int i = 1; i <= (container.getHeight() / delta_h); i++)
	{
		setColor(drawRect(x, y, (2 * container.getRadius()), delta_h + 1), faucet.getFluid().getColor().getRed(), faucet.getFluid().getColor().getGreen(), faucet.getFluid().getColor().getBlue());
		y -= delta_h;
		Sleep(200);
	}

	//Turn off Faucet
	faucet.turnOff();


}
