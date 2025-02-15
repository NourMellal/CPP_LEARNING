#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
    std::string name;
public:
    DiamondTrap ();
    ~DiamondTrap ();
    DiamondTrap(const std::string &name);
    DiamondTrap(const DiamondTrap &rhs);
    DiamondTrap &operator=(const DiamondTrap &rhs);

    void attack(const std::string &target);
    void whoAmI();
};

