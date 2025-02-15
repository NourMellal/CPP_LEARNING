#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default_FragTrap", 100, 100, 30) { 
    std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name, 100, 100, 30) {
    std::cout << "FragTrap " << name << " Parameterized constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &rhs) : ClapTrap(rhs) {
    std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs) {
    if (this != &rhs)
    {
        std::cout << "FragTrap Copy assignment operator called" << std::endl;
        ClapTrap::operator=(rhs);
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << _name << " Destructor called" << std::endl;
}


void    FragTrap::attack(const std::string &target)
{
    if (_hitpoints <= 0 || _energypoints <= 0)
    {
        std::cout << "FragTrap " << _name << " has no energy or hit points left to attack!" << std::endl;
        return;
    }

    _energypoints -= 1;
    std::cout << "FragTrap " << _name << " attacks " << target << ", causing "
              << _attack_dmg << " points of damage!" << std::endl;
}

void    FragTrap::highFivesGuys(void)
{
    if (_hitpoints != 0 && _energypoints != 0)
    {
        std::cout << "FragTrap " << _name << " is Requesting high fives!" << std::endl;
        _energypoints -= 1;
    }
    else {
        std::cout << "FragTrap " << _name << " has no energy or hit points left to highFives!" << std::endl;
    }
}