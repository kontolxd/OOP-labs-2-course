#include <iostream>
#include <algorithm>
#include <sstream>
#include "employe.h"
inline bool isInteger(const std::string & s)
{
   if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;
   char * p;
   strtol(s.c_str(), &p, 10);
   return (*p == 0);
}

struct NOTE
{
    std::string NAME;
    std::string TELE;
    int BDAY[3];
};

// method for struct
void exec()
{
    NOTE BLOCKNOTE[8];
    for(int i = 0; i < 8; i++)
    {
        std::string in;
        std::cout << "Enter name, surname, tele and birthday by space delimiter: ";
        std::getline(std::cin, in);
        std::stringstream buf(in);
        std::string name;
        std::string surname;
        std::string tele;
        std::string bday[3];
        getline(buf, name, ' ');
        getline(buf, surname, ' ');
        getline(buf, tele, ' ');
        getline(buf, bday[0], '.');
        getline(buf, bday[1], '.');
        getline(buf, bday[2], '.');
        getline(buf, in);

        if(!isInteger(bday[0]) || !isInteger(bday[1]) || !isInteger(bday[2]))
        {
            std::cout<<"Error. Birthday date must be number and have format: dd.mm.yyyy";
            return;
        }
        BLOCKNOTE[i].NAME = surname + " " + name;
        BLOCKNOTE[i].TELE = tele;
        BLOCKNOTE[i].BDAY[0] = std::atoi(bday[0].c_str());
        BLOCKNOTE[i].BDAY[1] = std::atoi(bday[1].c_str());
        BLOCKNOTE[i].BDAY[2] = std::atoi(bday[2].c_str());

    }

    std::sort(BLOCKNOTE, BLOCKNOTE + 8, [](NOTE &a, NOTE &b)
    {
      return a.TELE.substr(0, 3) < b.TELE.substr(0, 3);
    });

    std::string surname;
    std::cout << "Enter desired surname: ";
    std::cin >> surname;

    //Find
    bool flag = false;
    for(int i = 0; i < 8; i++)
    {
        std::stringstream s(BLOCKNOTE[i].NAME);
        std::string sur;
        getline(s, sur, ' ');
        if(sur == surname)
        {
            flag = true;
            std::cout << BLOCKNOTE[i].NAME << std::endl
                      << BLOCKNOTE[i].TELE << std::endl
                      << BLOCKNOTE[i].BDAY[0] << "."
                      << BLOCKNOTE[i].BDAY[1] << "."
                      << BLOCKNOTE[i].BDAY[2] << std::endl;

        }
    }
    if(!flag)
    {
        std::cout<<"Cannot find user with entered surname"<<std::endl;
    }
}

int main()
{
    Employe emp1("name1", 11, 1);
    Employe emp2("name2", 212, 2);
    Employe emp3("name3", 412, 3);
    Employe emp4("name4", 13, 4);

    emp1.setSalary(231);

    emp1.info();
    emp2.info();
    emp3.info();
    emp4.info();
}
