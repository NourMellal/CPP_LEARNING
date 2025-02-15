#include "HumanB.hpp"

HumanB::HumanB ( const std::string &name ) : name(name) { }

void HumanB::attack( void ) const {
    if (weapon)
    {
        std::cout << name << " attacks with their " << weapon->geyType() << std::endl ;
    }
    else
        std::cout <<  "No weapon for " << name << std::endl ;
}

void    HumanB::setWeapon ( Weapon &weapon ) {
    this->weapon = &weapon;
}


