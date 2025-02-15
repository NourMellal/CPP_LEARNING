#include "AMateria.hpp"

AMateria::AMateria(const std::string &type) : type(type) {}

AMateria::~AMateria() {}

std::string const &AMateria::getType(void) const {
    return this->type;
}

AMateria::AMateria(const AMateria& rhs) {
    (void)rhs;
    *this = rhs;
}

AMateria &AMateria::operator=(const AMateria& rhs) {
    (void)rhs;
    return *this;
}
