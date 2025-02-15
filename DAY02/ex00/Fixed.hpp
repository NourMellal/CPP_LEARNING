#pragma once

#include <iostream>

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

    int getRawBits(void) const;
    void setRawBits(int const raw);
};
