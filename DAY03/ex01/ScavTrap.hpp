#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
    ScavTrap();
    ScavTrap(const std::string &name);
    ScavTrap(const ScavTrap &rhs);
    ScavTrap &operator=(const ScavTrap &rhs);
    ~ScavTrap();
    void attack(const std::string &target);

    void    guardGate();
};