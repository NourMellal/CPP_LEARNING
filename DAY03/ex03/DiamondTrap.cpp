#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap(), name("Default") { 
    std::cout << "DiamondTrap Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name", 100, 100, 30), ScavTrap(), FragTrap(), name(name) {
    std::cout << "DiamondTrap " << name << " Parameterized constructor called" << std::endl;
}


DiamondTrap::DiamondTrap(const DiamondTrap &rhs) : ClapTrap(rhs), ScavTrap(rhs), FragTrap(rhs), name(rhs.name) {
    std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs) {
    if (this != &rhs)
    {
        ClapTrap::operator=(rhs);
        std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
        this->name = rhs.name;
    }
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << name << " Destructor called" << std::endl;
}


void    DiamondTrap::attack(const std::string &target)
{
    FragTrap::attack(target);
}

void    DiamondTrap::whoAmI(void) {
    std::cout << "I am a DiamondTrap " << name << ", And my ClapTrap name is " << ClapTrap::_name << std::endl;
}