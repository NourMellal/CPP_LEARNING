#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal") {
    std::cout << "AAnimal constructor called" << std::endl;
}
AAnimal::~AAnimal() {
    std::cout << "AAnimal destructor called" << std::endl;
}
AAnimal& AAnimal::operator=(AAnimal &rhs) {
    if (this != &rhs)
    {
        type = rhs.type;
    } 
    return *this;
}
AAnimal::AAnimal(AAnimal &rhs): type(rhs.type) {
    std::cout << "AAnimal copy constructor called" << std::endl;
}

std::string AAnimal::getType() const {
    return this->type;
}
