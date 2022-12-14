#include <iostream>

int main()
{
    std::string str = "a ss ddd dsadsadsadsad ffff ggggdg\n";
    int max = 0;
    int curLength = 0;
    int pos = 0;
    for(int i = 0; i < str.length(); i++)
    {
        curLength++;
        if(str[i] == ' ' || str[i] == '\n')
        {
            if(curLength > max)
            {
                pos = i - curLength + 1;
                max = curLength-1;
            }
            curLength = 0;
        }

    }
    std::cout<<pos<<std::endl;
    for(int i = 0; i < max; i++)
    {
        std::cout<<str[pos + i];
    }
    std::cout<<std::endl;
}
