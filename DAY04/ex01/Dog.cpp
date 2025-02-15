#include "Dog.hpp"

Dog::Dog() : brain(new Brain("Random Dog idea")){
    type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}
Dog::~Dog() {
    delete brain;
    std::cout << "Dog destructor called" << std::endl;
}
Dog &Dog::operator=(Dog &rhs) {
    if (this != &rhs)
    {
        type = rhs.type;
        delete brain;
        brain = new Brain(*rhs.brain);
    }
    return *this;
}
Dog::Dog(Dog &rhs) : Animal(rhs), brain(new Brain(*rhs.brain)) {
    type = rhs.type;
    std::cout << "Dog copy constructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof!" << std::endl;
}
