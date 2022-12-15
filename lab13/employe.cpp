#include "employe.h"

Employe::Employe(std::string name, int salary, int id) : name(name), salary(salary), id(id)
{}

void Employe::info()
{
    std::cout << "Name: " << name << std::endl <<
                 "Salary: " << salary << std::endl <<
                 "Id: " << id << std::endl;
}

void Employe::setId(int id)
{
    this->id = id;
}

void Employe::setName(std::string name)
{
    this->name = name;
}

void Employe::setSalary(int salary)
{
    this->salary = salary;
}

std::string Employe::getName()
{
    return name;
}

int Employe::getId()
{
    return id;
}

int Employe::getSalary()
{
    return salary;
}
