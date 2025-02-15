#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
    Brain *brain;
public:
    ~Cat();
    Cat();
    Cat(Cat &rhs);
    Cat &operator=(Cat &rhs);

    void makeSound() const ;
};

