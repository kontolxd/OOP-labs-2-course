#include <iostream>
//1 вариант, моего 14 там нету(

double ctok(double c) // преобразует шкалу Цельсия в шкалу Кельвина
{
    int k = c + 273.15;
    return k;
}

int main()
{
    double d;
    double c = 0; // объявляем переменную для ввода
    std::cin >> d; // вводим температуру в переменную ввода
    double k = ctok(c); // преобразуем температуру
    std::cout << k << std::endl ; // выводим температуру на печать
}
