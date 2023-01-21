#include "player.h"

inline bool isInteger(const std::string & s)
{
    if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;
    char * p;
    strtol(s.c_str(), &p, 10);
    return (*p == 0);
}

Player::Player()
{
    name = "You";
    health = 100;
    power = 5;
}

void Player::step(Alive &target)
{
    std::string _answ;
    int answ;
    while(true)
    {
        std::cout<<"Enter your step (0 - attack, 1 - heal): ";
        std::cin>>_answ;
        if(isInteger(_answ))
        {
            answ = std::stoi(_answ);
            if(answ >= 2) continue;
        }
        else continue;
        break;
    }
    switch(answ)
    {
    case 0:
        attack(target);
        break;
    case 1:
        takeDamage(-power);
        break;
    }
}
