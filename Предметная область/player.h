#pragma once
#include <iostream>
#include "alive.h"

class Player : public Alive
{
public:
    void step(Alive&);
    Player();
};
