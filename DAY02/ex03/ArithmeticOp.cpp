
#include "Fixed.hpp"

Fixed Fixed::operator+(const Fixed &other)
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other)
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other)
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other)
{
    if (other._rawbits == 0)
    {
        std::cerr << "Error : Devision by 0" << std::endl ;
        return Fixed(0);
    }
    return Fixed(this->toFloat() / other.toFloat());
}


Fixed Fixed::operator+(const Fixed &other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
    if (other._rawbits == 0)
    {
        std::cerr << "Error : Devision by 0" << std::endl ;
        return Fixed(0);
    }
    return Fixed(this->toFloat() / other.toFloat());
}