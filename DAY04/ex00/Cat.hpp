#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
public:
    ~Cat();
    Cat();
    Cat(Cat &rhs);
    Cat &operator=(Cat &rhs);
    void makeSound() const ;
};

