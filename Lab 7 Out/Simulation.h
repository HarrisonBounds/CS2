#pragma once
#ifndef SIMULATION_H
#define SIMULATION_H

#include "Container.h"
#include "Faucet.h"

class Simulation
{
private:
    Faucet faucet;
    Container container;
    int waterRate;

public:
    Simulation();
    void setContainer(Container container);
    Container getContainer();
    void setFaucet(Faucet faucet);
    Faucet getFaucet();
    int getWaterRate();
    void setWaterRate(int waterRate);
    void draw();
    void start();
};

#endif
