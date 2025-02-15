#include "Fixed.hpp"

bool Fixed::operator>(const Fixed &other) const 
{
    return this->_rawbits > other._rawbits;
}

bool Fixed::operator<(const Fixed &other) const 
{
    return this->_rawbits < other._rawbits;
}

bool Fixed::operator!=(const Fixed &other) const 
{
    return this->_rawbits != other._rawbits;
}

bool Fixed::operator==(const Fixed &other) const 
{
    return this->_rawbits == other._rawbits;
}

bool Fixed::operator>=(const Fixed &other) const 
{
    return this->_rawbits >= other._rawbits;
}

bool Fixed::operator<=(const Fixed &other) const 
{
    return this->_rawbits <= other._rawbits;
}