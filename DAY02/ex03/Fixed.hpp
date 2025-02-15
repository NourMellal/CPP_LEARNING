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

    Fixed &operator++();
    Fixed operator++(int);
    Fixed &operator--();
    Fixed operator--(int);

    Fixed operator+(const Fixed &other);
    Fixed operator-(const Fixed &other);
    Fixed operator*(const Fixed &other);
    Fixed operator/(const Fixed &other);
    Fixed operator+(const Fixed &other) const ;
    Fixed operator-(const Fixed &other) const ;
    Fixed operator*(const Fixed &other) const ;
    Fixed operator/(const Fixed &other) const ;
    
    bool operator>(const Fixed &other) const ;
    bool operator<(const Fixed &other) const ;
    bool operator==(const Fixed &other) const ;
    bool operator!=(const Fixed &other) const ;
    bool operator>=(const Fixed &other) const ;
    bool operator<=(const Fixed &other) const ;

    static const Fixed &max(const Fixed& a, const Fixed& b) ;
    static const Fixed &min(const Fixed& a, const Fixed& b);
    static Fixed &min(Fixed& a, Fixed& b);
    static Fixed &max(Fixed& a, Fixed& b) ;


    Fixed( const float fixed );
    Fixed( const int fixed );

    float toFloat( void ) const ;
    int toInt( void ) const ;

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &os, const Fixed& fixed);