#include <iostream>
#include <cstdlib>
#include <cstring>
void arrays();
inline bool isInteger(const std::string & s)
{
   if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;
   char * p;
   strtol(s.c_str(), &p, 10);
   return (*p == 0);
}

int main()
{
    std::cout<<"Enter N and M: "<<std::endl;
    int N, M;
    std::string nn, mm;
    std::cin>>nn>>mm;
    if(!isInteger(nn) || !isInteger(mm))
    {
        std::cout<<"Error: N and M must be number"<<std::endl;
        return -1;
    }

    N = atoi(nn.c_str());
    M = atoi(mm.c_str());

    int matrix[N][M];
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            matrix[i][j] = std::rand()%100 - 50;
        }
    }

    int max = -100, maxPos;
    int min = 100, minPos;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(matrix[i][j] > max)
            {
                max = matrix[i][j];
                maxPos = i;
            }
            else if(matrix[i][j] < min)
            {
                min = matrix[i][j];
                minPos = i;
            }
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            std::cout<<matrix[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;

    int tmpMin[M];
    for(int i = 0; i < M; i++)
    {
        tmpMin[i] = matrix[minPos][i];
    }
    int tmpMax[M];
    for(int i = 0; i < M; i++)
    {
        tmpMax[i] = matrix[maxPos][i];
    }
    for(int i = 0; i < M; i++)
    {
        matrix[minPos][i] = tmpMax[i];
        matrix[maxPos][i] = tmpMin[i];
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            std::cout<<matrix[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}

void arrays()
{
    int in;
    std::string _in;
    std::string *array;
    array = new std::string[5];
    for(int i = 0; i < 5; i++)
    {
        array[i] = "string " + std::to_string(i);
    }
    std::cout << "Enter number: ";
    std::cin >> _in;

    if(!isInteger(_in))
    {
        std::cout<<"Input must be integer!"<<std::endl;
        return;
    }

    in = atoi(_in.c_str());

    array[in].erase();
    for(int i = 0; i < 5; i++)
    {
        std::cout<<array[i]<<std::endl;
    }
    delete [] array;
}
