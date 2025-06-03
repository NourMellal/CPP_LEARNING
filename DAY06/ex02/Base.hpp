#ifndef BASE_HPP
#define BASE_HPP

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <exception>

class Base {
public:
    Base();
    virtual ~Base();
};


void identify(Base* p);
void identify(Base& p);
Base* generate(void);

#endif // BASE_HPP