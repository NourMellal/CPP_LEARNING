#include "Fixed.hpp"


Fixed &Fixed::operator++()
{
    _rawbits++;
    return *this;
}

Fixed &Fixed::operator--()
{
    _rawbits--;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    _rawbits++ ;
    return temp;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    _rawbits-- ;
    return temp;
}
