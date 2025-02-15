#pragma once

#include "Animal.hpp"
#include "Brain.hpp"
class Dog : public Animal
{
private:
    Brain *brain;
public:
    ~Dog();
    Dog();
    Dog(Dog &rhs);
    Dog &operator=(Dog &rhs);

    void makeSound() const ;
};
