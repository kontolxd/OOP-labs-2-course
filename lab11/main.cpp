#include <iostream>
#include <chrono>
#include <fstream>
#include <list>
bool isInteger(const std::string & s);

struct NOTE
{
    std::string name;
    std::string tele;
    std::chrono::year_month_day *birthday;
};

int main()
{
    std::string buf;
    std::list<NOTE> notes;
    std::ifstream fin("notes.txt");
    if(!fin.is_open())
    {
        std::cout<<"Field to open file notes.txt"<<std::endl;
        return 0;
    }
    getline(fin, buf);
    if(!isInteger(buf))
    {
        std::cout<<"First line must be integer!"<<std::endl;
        return 0;
    }
    int len = std::atoi(buf.c_str());
    for(int i = 0; i < len; i++)
    {
        NOTE note;
        getline(fin, buf);
        note.name = buf;
        getline(fin, buf);
        note.tele = buf;
        getline(fin, buf, '.');
        int day, month, year;
        if(!isInteger(buf))
        {
            std::cout<<"Error. All birthday components must be a number!"<<std::endl;
            return 0;
        }
        day = std::atoi(buf.c_str());
        getline(fin, buf, '.');
        if(!isInteger(buf))
        {
            std::cout<<"Error. All birthday components must be a number!"<<std::endl;
            return 0;
        }
        month = std::atoi(buf.c_str());
        getline(fin, buf);
        if(!isInteger(buf))
        {
            std::cout<<"Error. All birthday components must be a number!"<<std::endl;
            return 0;
        }
        year = std::atoi(buf.c_str());

        std::chrono::day _day(day);
        std::chrono::month _month(month);
        std::chrono::year _year(year);

        note.birthday = new std::chrono::year_month_day(_year, _month, _day);
        notes.push_back(note);
    }

    while(true)
    {
        std::cout<<"Enter a month number: ";
        std::cin>>buf;
        if(!isInteger(buf))
        {
            std::cout<<"Input number must be integer! Retry"<<std::endl;
            continue;
        }
        bool flag = false;
        int in = std::atoi(buf.c_str());
        for(auto it : notes)
        {
            if(in == unsigned(it.birthday->month()))
            {
                flag = true;
                std::cout<<"Name: " << it.name << std::endl <<
                           "Tele: " << it.tele << std::endl <<
                           "Birthday: " <<  unsigned(it.birthday->day()) <<
                           "." << unsigned(it.birthday->month()) <<
                           "." << int(it.birthday->year()) <<
                           std::endl;
            }
        }
        if(flag)
            break;
        else
        {
            std::cout<<"Cannot find people with month birthday" << in << ". Retry." << std::endl;
        }
    }
}

inline bool isInteger(const std::string & s)
{
    if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;
    char * p;
    strtol(s.c_str(), &p, 10);
    return (*p == 0);
}
