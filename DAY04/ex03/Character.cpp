#include "Character.hpp"

Character::~Character() {
    for (int i = 0; i < 4; i++) {
        if (this->inventory[i]) {
            std::cout << "deleted matrila type " << inventory[i]->getType() << " at index " << i <<  std::endl;
            delete this->inventory[i];
        }
    }
}

Character::Character(void) : name("default") {
    for (int i = 0; i < 4; i++) {
        inventory[i] = NULL;
    }
}

Character::Character(const std::string &name) : name(name) {
    for (int i = 0; i < 4; i++) {
        inventory[i] = NULL;
    }
}

Character::Character(const Character &rhs) : ICharacter(rhs) {
    this->name = rhs.name;
    for (int i = 0; i < 4; i++) {
        if (rhs.inventory[i]) {
            this->inventory[i] = rhs.inventory[i]->clone();
        } else {
            this->inventory[i] = NULL;
        }
    }
}

Character &Character::operator=(const Character &rhs) {
    if (this != &rhs) {
        for (int i = 0; i < 4; i++) {
            delete inventory[i];
            inventory[i] = NULL;
        }
        for (int i = 0; i < 4; i++) {
            if (rhs.inventory[i]) {
                inventory[i] = rhs.inventory[i]->clone();
            }
        }
        this->name = rhs.name;
    }
    return *this;
}

std::string const &Character::getName() const {
    return this->name;
}

void Character::equip(AMateria *m) {
    if (!m)
        return;
    for (int i = 0; i < 4; i++) {
        if (!this->inventory[i]) {
            this->inventory[i] = m;
            std::cout << "character " << this->getName() << " equiped a " << m->getType() << '\n';
            return;
        }
    }
}

bool Character::isInInventory(AMateria *m) const {
    for (int i = 0; i < 4; i++) {
        if (m == this->inventory[i])
            return true;
    }
    return false;
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4 && inventory[idx]) {
        inventory[idx] = NULL;
    } else {
        std::cerr << "Cannot unequip material at idx: " << idx << std::endl;
    }
}

void Character::use(int idx, ICharacter &target) {
    if (idx >= 0 && idx < 4 && inventory[idx]) {
        inventory[idx]->use(target);
    } else {
        std::cerr << "Cannot use material at idx: " << idx << std::endl;
    }
}
