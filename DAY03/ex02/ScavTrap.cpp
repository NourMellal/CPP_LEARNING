#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default_ScavTrap", 100, 50, 20) { 
    std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name, 100, 50, 20) {
    std::cout << "ScavTrap " << name << " Parameterized constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &rhs) : ClapTrap(rhs) {
    std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs) {
    if (this != &rhs)
    {
        std::cout << "ScavTrap Copy assignment operator called" << std::endl;
        ClapTrap::operator=(rhs);
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << _name << " Destructor called" << std::endl;
}


void    ScavTrap::attack(const std::string &target)
{
    if (_hitpoints <= 0 || _energypoints <= 0)
    {
        std::cout << "ScavTrap " << _name << " has no energy or hit points left to attack!" << std::endl;
        return;
    }

    _energypoints -= 1;
    std::cout << "ScavTrap " << _name << " attacks " << target << ", causing "
              << _attack_dmg << " points of damage!" << std::endl;
}

void  ScavTrap::guardGate()
{
    if (_energypoints != 0 && _hitpoints != 0)
    {
        _energypoints--;
        std::cout << "ScavTrap " << _name << " in Gate keeper mode" << std::endl;
    }
    else
        std::cout << "ScavTrap " << _name << " has no more Energy Points or Hit Points to guard gate." << std::endl;
}
