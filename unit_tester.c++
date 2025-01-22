#include <iostream>
#include <ctime>

void displayTimestamp()
{

    time_t curr_time;
    struct tm *date;

    curr_time = time(NULL);
    date = localtime(&curr_time);

    std::cout << "[" << (date->tm_year + 1900);

    if (date->tm_mon + 1 < 10)
    {
        std::cout << "0";
    }
    std::cout << (date->tm_mon + 1);

    if (date->tm_mday < 10)
    {
        std::cout << "0";
    }
    std::cout << date->tm_mday << "_";
    
    if (date->tm_hour < 10)
    {
        std::cout << "0";
    }
    std::cout << date->tm_hour;
    
    if (date->tm_min < 10)
    {
        std::cout << "0";
    }
    std::cout << date->tm_min;
    
    if (date->tm_sec < 10)
    {
        std::cout << "0";
    }
    std::cout << date->tm_sec << "] ";
}

int main(int argc, char const *argv[])
{
    displayTimestamp();
    return 0;
}
