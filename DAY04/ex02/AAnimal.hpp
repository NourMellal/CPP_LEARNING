#pragma once

#include <string>
#include <iostream>
class AAnimal
{
protected:
    std::string type;

public:
    virtual ~AAnimal();
    AAnimal();
    AAnimal(AAnimal &rhs);
    AAnimal &operator=(AAnimal &rhs);

    std::string getType() const;
    void virtual makeSound() const = 0;
};
