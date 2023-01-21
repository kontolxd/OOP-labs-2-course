#include "orc.h"

Orc::Orc()
{
    health = 20;
    power = 5;
    name = "Orc";
    for(int i = 0; i < 8; i++)
        inventory[i] = rand() % 10;
}

void Orc::battleRoar()
{
    health--;
    power += 2;
    printf("%s lets out a battle cry!\n", name.c_str());
}

void Orc::step(Alive &target)
{
    srand(std::time(0));
    // 0 - attack
    // 1 - heal
    // 2 - battle roar
    int decide = rand() % 3;
    switch(decide)
    {
    case 0:
        attack(target);
        break;
    case 1:
        printf("%s heal himself.\n", name.c_str());
        takeDamage(-power);
        break;
    case 2:
        battleRoar();
        break;
    }
}
