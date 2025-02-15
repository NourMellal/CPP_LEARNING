#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::~Cure() {}

Cure::Cure(const Cure& rhs) : AMateria("cure") {
    (void)rhs;
}

Cure &Cure::operator=(const Cure& rhs) {
    (void)rhs;
    return *this;
}

AMateria* Cure::clone(void) {
    return new Cure();
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
