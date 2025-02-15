#pragma once

#include "ClapTrap.hpp"


class FragTrap : virtual public ClapTrap {
private:

public:
    FragTrap();
    FragTrap(const std::string &name);
    FragTrap(const FragTrap& rhs);
    FragTrap &operator=(const FragTrap& rhs);
    ~FragTrap();

    void    attack(const std::string &target);
    void    highFivesGuys(void);
};