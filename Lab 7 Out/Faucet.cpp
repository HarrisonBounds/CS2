#include "GenPoint.h"
#include "Fluid.h"
#include "Faucet.h"
#include "graph1.h"
#include <iostream>
#include "Container.h"

using namespace std;

Faucet::Faucet()
{
	pos.setPoint(0, 0);
	setFluid(fluid);
}

void Faucet::turnOn()
{
	setColor(drawLine(fluid.getStart().getX(), fluid.getStart().getY(), fluid.getEnd().getX(), fluid.getEnd().getY(), 1), fluid.getColor().getRed(), fluid.getColor().getGreen(), fluid.getColor().getBlue());
}

void Faucet::turnOff()
{
	setColor(drawLine(fluid.getStart().getX(), fluid.getStart().getY(), fluid.getEnd().getX(), fluid.getFillLine(), 1), 0, 0, 0);
}

void Faucet::setPosition(GenPoint upper)
{
	this->pos.setPoint(upper.getX(), upper.getY());
}

GenPoint Faucet::getPosition()
{
	return pos;
}

void Faucet::setFluid(Fluid fluid)
{
	this->fluid = fluid;
}

Fluid Faucet::getFluid()
{
	return fluid;
}

void Faucet::draw()
{
	int x_faucet = pos.getX();
	int y_faucet = pos.getY();
	displayBMP("faucet.bmp", pos.getX(), pos.getY());
}