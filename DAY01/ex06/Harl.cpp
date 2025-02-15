
#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << " [DEBUG] " << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << " [INFO] " << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << " [WARNING] " << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << " [ERROR] " << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complainFilter(std::string level)
{

    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    int startfallthrough = -1;
    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
        {
            startfallthrough = i;
            break;
        }
    }
        switch (startfallthrough)
        {
        case 0:
            this->debug();
        case 1:
            this->info();
        case 2:
            this->warning();
        case 3:
            this->error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        }
}