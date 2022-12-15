#pragma once
#include <iostream>

class Employe
{
private:
    std::string name;
    unsigned int salary;
    unsigned int id;
public:
    Employe(std::string name = "", int salary = 0, int id = 0);
    //Print info
    void info();
    //Setters
    void setSalary(int);
    void setName(std::string);
    void setId(int);
    //Getters
    int getSalary();
    int getId();
    std::string getName();
};
