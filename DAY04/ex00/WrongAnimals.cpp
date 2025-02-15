#include "WrongAnimals.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "WrongAnimal constructor called" << std::endl;
}
WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}
WrongAnimal &WrongAnimal::operator=(WrongAnimal &rhs)
{
    if (this != &rhs)
    {
        type = rhs.type;
    }
    return *this;
}
WrongAnimal::WrongAnimal(WrongAnimal &rhs) : type(rhs.type)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sound!" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "WrongCat constructor called" << std::endl;
}
WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}
WrongCat &WrongCat::operator=(WrongCat &rhs)
{
    if (this != &rhs)
    {
        type = rhs.type;
    }
    return *this;
}
WrongCat::WrongCat(WrongCat &rhs) : WrongAnimal(rhs)
{
    type = rhs.type;
    std::cout << "WrongCat copy constructor called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "Meoow!" << std::endl;
}

WrongDog::WrongDog()
{
    type = "WrongDog";
    std::cout << "WrongDog constructor called" << std::endl;
}
WrongDog::~WrongDog()
{
    std::cout << "WrongDog destructor called" << std::endl;
}
WrongDog &WrongDog::operator=(WrongDog &rhs)
{
    if (this != &rhs)
    {
        type = rhs.type;
    }
    return *this;
}
WrongDog::WrongDog(WrongDog &rhs) : WrongAnimal(rhs)
{
    type = rhs.type;
    std::cout << "WrongDog copy constructor called" << std::endl;
}

void WrongDog::makeSound() const
{
    std::cout << "Woof!" << std::endl;
}