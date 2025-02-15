#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int _rawbits;
    const static int _frac = 8;

public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);

    Fixed( const float fixed );
    Fixed( const int fixed );

    float toFloat( void ) const ;
    int toInt( void ) const ;

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &os, const Fixed& fixed);