#pragma once
#include <random>
#include <ctime>
#include "alive.h"

class Stealer;

class Orc : public Alive
{
public:
    Orc();

    void battleRoar();

    virtual void step(Alive&);

    friend Stealer;
};

class Stealer
{
public:
    void steal(Orc& orc, int num)
    {
        if(num > 8){}
        else
            orc.inventory[num] = -1;
    }
};
