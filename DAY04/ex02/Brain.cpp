#include "Brain.hpp"

Brain::Brain(const std::string &idea)
{
    for (size_t i = 0; i < sizeof(ideas) / sizeof(std::string); i++)
    {
        ideas[i] = "This brain thinking of " + idea;
    }
    std::cout << "Brain Constructor called\n";
}

Brain::Brain(const Brain &rhs)
{
    for (size_t i = 0; i < sizeof(ideas) / sizeof(std::string); i++)
    {
        ideas[i] = rhs.ideas[i];
    }
    std::cout << "Brain Copy Constructor called\n";
}

Brain &Brain::operator=(const Brain &rhs)
{
    if (this != &rhs)
    {
        for (size_t i = 0; i < sizeof(ideas) / sizeof(std::string); i++)
        {
            ideas[i] = rhs.ideas[i];
        }
    }
    std::cout << "Brain Copy Assignment operator called\n";
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain Destructor called\n";
}
