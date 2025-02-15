

#include "Weapon.hpp"

Weapon::Weapon ( const std::string &type ) : type(type) { }

const std::string &Weapon::geyType( void ) const {
    return (this->type) ;
}

void  Weapon::setType( const std::string  &type ) {
    this->type = type ;
}
