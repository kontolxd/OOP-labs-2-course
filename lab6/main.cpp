#include <iostream>
#include <cmath>
//first variant
double zxc(double x, double n)
{
    double mul;
    for (int i = 0; i < n; i++)
    {
        mul = std::log(1 + (x/(7+x)) * std::sqrt(i));
    }
    return (x + (x / (7 + x)) * mul);
}

int main()
{
    double a, b;
    std::cin>>a>>b;
    std::cout << zxc(a, b);
}
