#include "Fixed.hpp"

Fixed::Fixed() : _rawbits(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_rawbits = other.getRawBits();
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}


Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::Fixed( const float fixed )
{
    std::cout << "Float constructor called" << std::endl;
    _rawbits = roundf(fixed * (1 << _frac));
}

Fixed::Fixed( const int fixed )
{
    std::cout << "Int constructor called" << std::endl;
    _rawbits = (fixed << _frac);
}

float Fixed::toFloat( void ) const 
{
    return (float)_rawbits / (1 << _frac);
}

int Fixed::toInt( void ) const
{
    return (float)_rawbits / (1 << _frac);
}


Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_rawbits;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_rawbits = raw;
}
