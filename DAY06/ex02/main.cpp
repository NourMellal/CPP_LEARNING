#include "Base.hpp"

int main()
{
    // Initialize random seed once at program start
    srand(time(0));
    
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