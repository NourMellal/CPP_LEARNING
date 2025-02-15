#include "Cat.hpp"

Cat::Cat() {
    type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}
Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}
Cat &Cat::operator=(Cat &rhs) {
    if (this != &rhs)
    {
        type = rhs.type;
    }
    return *this;
}
Cat::Cat(Cat &rhs) : Animal(rhs){
    type = rhs.type;
    std::cout << "Cat copy constructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meoow!" << std::endl;
}