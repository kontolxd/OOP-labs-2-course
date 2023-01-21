#pragma once
#include <iostream>
class Alive
{
protected:
    std::string name;
    int inventory[8];
    int health;
    int power;
public:
    int getHealth();
    int getPower();

    void takeDamage(int dmg);
    void attack(Alive&);

    bool isAlive();

    bool operator==(Alive&);

    virtual void step(Alive&) = 0;
};
