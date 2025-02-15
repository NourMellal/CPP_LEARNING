#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
public:
    Ice();
    ~Ice();
    Ice(const Ice& rhs);
    Ice &operator=(const Ice& rhs);
    AMateria* clone(void);
    void use(ICharacter& target);
};

#endif
