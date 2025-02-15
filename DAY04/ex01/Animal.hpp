#pragma once

#include <string>
#include <iostream>
class Animal
{
protected:
    std::string type;

public:
    virtual ~Animal();
    Animal();
    Animal(Animal &rhs);
    Animal &operator=(Animal &rhs);

    std::string getType() const;
    void virtual makeSound() const;
};
