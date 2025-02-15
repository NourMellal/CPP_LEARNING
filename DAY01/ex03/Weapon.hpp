#pragma once

#include <string>
#include <iostream>


class Weapon {

    private:
        std::string type ;
    public:
        Weapon( const std::string &type ) ;
        const std::string &geyType( void ) const ;
        void  setType( const std::string  &type ) ;
};