#include <iostream>
#include "player.h"
#include "orc.h"
int main()
{
    Orc *orc = new Orc();
    Player *player = new Player();
    while(orc->isAlive() && player->isAlive())
    {
        orc->step(*player);
        player->step(*orc);
    }
}
