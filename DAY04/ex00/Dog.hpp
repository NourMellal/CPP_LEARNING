#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
public:
    ~Dog();
    Dog();
    Dog(Dog &rhs);
    Dog &operator=(Dog &rhs);

    void makeSound() const ;
};
