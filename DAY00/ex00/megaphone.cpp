#include <iostream>
#include <cctype>

struct Megaphone
{

    void shout(const std::string &str) const
    {
        for (size_t j = 0; j < str.length(); j++)
        {
            std::cout << (char)std::toupper(str[j]);
        }
    };
};

    int main(int ac, char **av)
    {
        if (ac == 1)
        {
            std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
            return (0);
        }
        
        Megaphone meg;
        for (int i = 1; i < ac; i++)
        {
            meg.shout(av[i]);
            if (i < ac - 1)
                std::cout << " ";
        }
        std::cout << std::endl;
        return (0);
    }