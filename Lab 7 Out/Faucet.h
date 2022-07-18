#pragma once
#ifndef FAUCET_H
#define FAUCET_H

#include "GenPoint.h"
#include "Fluid.h"

class Faucet
{
private:
    GenPoint pos;
    Fluid fluid;

public:
    Faucet();
    void turnOn();
    void turnOff();
    void setPosition(GenPoint upper);
    GenPoint getPosition();
    void setFluid(Fluid fluid);
    Fluid getFluid();
    void draw();

};

#endif
