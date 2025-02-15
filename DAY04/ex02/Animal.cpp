#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "Animal constructor called" << std::endl;
}
Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}
Animal& Animal::operator=(Animal &rhs) {
    if (this != &rhs)
    {
        type = rhs.type;
    } 
    return *this;
}
Animal::Animal(Animal &rhs): type(rhs.type) {
    std::cout << "Animal copy constructor called" << std::endl;
}

void Animal::makeSound() const{
    std::cout << "Animal sound!" << std::endl;
}

std::string Animal::getType() const {
    return this->type;
}
