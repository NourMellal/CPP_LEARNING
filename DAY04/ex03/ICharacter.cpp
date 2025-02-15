#include "ICharacter.hpp"

ICharacter::~ICharacter() {}

ICharacter::ICharacter() {}

ICharacter::ICharacter(const ICharacter &rhs) {
    *this = rhs;
}

ICharacter &ICharacter::operator=(const ICharacter &rhs) {
    (void)rhs;
    return *this;
}
