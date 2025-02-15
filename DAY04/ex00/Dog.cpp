#include "Dog.hpp"

Dog::Dog() {
    type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}
Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}
Dog &Dog::operator=(Dog &rhs) {
    if (this != &rhs)
    {
        type = rhs.type;
    }
    return *this;
}
Dog::Dog(Dog &rhs) : Animal(rhs) {
    type = rhs.type;
    std::cout << "Dog copy constructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof!" << std::endl;
}