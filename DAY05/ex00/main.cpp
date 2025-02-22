#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat nour = Bureaucrat("nour", 155);
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }
    try
    {
        Bureaucrat bob = Bureaucrat("bob", 0);
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }

    Bureaucrat *me;
    try
    {
        me = new Bureaucrat("me", 1);
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }
    std::cout << *me;
    delete me;
}