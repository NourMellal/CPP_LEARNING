#pragma once

#include <string>
#include <iostream>

class WrongAnimal
{
protected:
    std::string type;

public:
    virtual ~WrongAnimal();
    WrongAnimal();
    WrongAnimal(WrongAnimal &rhs);
    WrongAnimal &operator=(WrongAnimal &rhs);

    std::string getType() const;
    void makeSound() const;
};

class WrongDog : public WrongAnimal
{
public:
    ~WrongDog();
    WrongDog();
    WrongDog(WrongDog &rhs);
    WrongDog &operator=(WrongDog &rhs);

    void makeSound() const;
};

class WrongCat : public WrongAnimal
{
public:
    ~WrongCat();
    WrongCat();
    WrongCat(WrongCat &rhs);
    WrongCat &operator=(WrongCat &rhs);
    void makeSound() const;
};
