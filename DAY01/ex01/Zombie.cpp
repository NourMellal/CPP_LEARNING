
#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) : name(name) {}

Zombie::Zombie( ) : name("") {} ;

Zombie::~Zombie() { 
    std::cout << name << ": Has been Destroyed" << std::endl ;
}

void Zombie::announce (void) const {
    std::cout << name + ": " << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setZombieName( std::string name) {
    this->name = name;
}