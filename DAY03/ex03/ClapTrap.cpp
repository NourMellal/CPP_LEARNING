#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitpoints(10), _energypoints(10), _attack_dmg(0)
{
    std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name, unsigned int hp, unsigned int ep, unsigned int ad) : _name(name), _hitpoints(hp), _energypoints(ep), _attack_dmg(ad)
{
    std::cout << "ClapTrap " << name << " Parameterized constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &rhs) : _name(rhs._name) , _hitpoints(rhs._hitpoints), _energypoints(rhs._energypoints), _attack_dmg(rhs._attack_dmg)
{
    std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
    if (this != &rhs)
    {
        std::cout << "ClapTrap Copy assignment operator called" << std::endl;
        _name = rhs._name;
        _hitpoints = rhs._hitpoints;
        _energypoints = rhs._energypoints;
        _attack_dmg = rhs._attack_dmg;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " Destructor called" << std::endl;
}


void ClapTrap::attack(const std::string &target)
{
    if (_hitpoints <= 0 || _energypoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " has no energy or hit points left to attack!" << std::endl;
        return;
    }

    _energypoints -= 1;
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
              << _attack_dmg << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitpoints <= 0 || _energypoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " can't be repaired (no energy or hit points left)!" << std::endl;
        return;
    }

    _energypoints -= 1;
    _hitpoints += amount;
    std::cout << "ClapTrap " << _name << " repairs itself for " << amount
              << " hit points. Now has " << _hitpoints << " hit points!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    _hitpoints = (amount > _hitpoints) ? 0 : _hitpoints - amount;
    std::cout << "ClapTrap " << _name << " takes " << amount
              << " damage and now has " << _hitpoints << " hit points left!" << std::endl;
}
