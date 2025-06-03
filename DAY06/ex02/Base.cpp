#include "Base.hpp"
#include "ABC.hpp"
#include <typeinfo>

Base::Base() {}
Base::~Base() {}

void identify(Base* p)
{
    std::cout << (dynamic_cast<A*>(p) ? "A\n" : (dynamic_cast<B*>(p) ? "B\n" : (dynamic_cast<C*>(p) ? "C\n" : "Non\n")));
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A\n";
        return;
    } catch (std::bad_cast&) {}
    
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B\n";
        return;
    } catch (std::bad_cast&) {}

    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C\n";
        return;
    } catch (std::bad_cast&) {}
}

Base* generate(void)
{
    int n = rand() % 3;
    std::cout << n << std::endl;
    
    if (n == 0)
        return new A();
    else if (n == 1)
        return new B();
    else
        return new C();
}