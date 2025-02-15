#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::~Ice() {}

Ice::Ice(const Ice& rhs) : AMateria("ice") {
    (void)rhs;
}

Ice &Ice::operator=(const Ice& rhs) {
    (void)rhs;
    return *this;
}

AMateria* Ice::clone(void) {
    return new Ice();
}

void Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
