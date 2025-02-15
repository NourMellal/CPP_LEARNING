#pragma once

#include <iostream>

class ClapTrap
{
protected:
    std::string _name;
    unsigned int _hitpoints;
    unsigned int _energypoints;
    unsigned int _attack_dmg;

public:
    ClapTrap();
    ClapTrap(const std::string &name, unsigned int hp = 10, unsigned int ep = 10, unsigned int ad = 0);
    ClapTrap(const ClapTrap &rhs);
    ClapTrap &operator=(const ClapTrap &rhs);
    virtual ~ClapTrap();

    virtual void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};
