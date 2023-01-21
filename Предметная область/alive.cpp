#include "alive.h"

int Alive::getHealth()
{
    return health;
}

int Alive::getPower()
{
    return power;
}

void Alive::attack(Alive& enemy)
{
    printf("%s beat %s and deal %d damage.\n", name.c_str(), enemy.name.c_str(), power);
    enemy.takeDamage(power);
}

void Alive::takeDamage(int dmg)
{
    health -= dmg;
    printf("%s have %d hp.\n", name.c_str(), health);
}

bool Alive::isAlive()
{
    if(health > 0) return true;
    else return false;
}

bool Alive::operator==(Alive& obj)
{
    int ret = true;
    if(health == obj.health && power == obj.power)
    {
        for(int i = 0; i < 8; i++)
        {
            if(inventory[i] != obj.inventory[i])
                ret = false;
        }
    }
    else ret = false;
    return ret;
}
