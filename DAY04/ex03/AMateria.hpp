#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

class AMateria {
protected:
    std::string type;

public:
    AMateria(const std::string &type);
    AMateria(const AMateria& rhs);
    AMateria &operator=(const AMateria& rhs);
    virtual ~AMateria();

    std::string const &getType(void) const;
    virtual AMateria* clone(void) = 0;
    virtual void use(ICharacter& target) = 0;
};

#endif
