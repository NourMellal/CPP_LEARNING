#include "Cat.hpp"

Cat::Cat() : brain(new Brain("Random cat idea")){
    type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}
Cat::~Cat() {
    delete brain;
    std::cout << "Cat destructor called" << std::endl;
}
Cat &Cat::operator=(Cat &rhs) {
    if (this != &rhs)
    {
        type = rhs.type;
        delete brain;
        brain = new Brain(*rhs.brain);
    }
    return *this;
}
Cat::Cat(Cat &rhs) : Animal(rhs), brain(new Brain(*rhs.brain)) {
    type = rhs.type;
    std::cout << "Cat copy constructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meoow!" << std::endl;
}
