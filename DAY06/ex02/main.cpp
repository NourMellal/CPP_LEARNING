#include "Base.hpp"

int main()
{    
    while (1)
    {
        Base* base = generate();
        identify(base);
        identify(*base);
        delete base;
        std::cout << "Press Enter to run again...\n";
        std::cin.get();
    }
    
    return 0;
}