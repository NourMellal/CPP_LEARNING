#include "DiamondTrap.hpp"

int main() {
    std::cout << "\n=== Creating DiamondTrap ===\n";
    DiamondTrap diamond1("Titanium");
    DiamondTrap diamond2(diamond1);  // Copy constructor test
    DiamondTrap diamond3;
    diamond3 = diamond1;  // Copy assignment test

    std::cout << "\n=== Testing Attack ===\n";
    diamond1.attack("Enemy Bot");
    diamond2.attack("Enemy Bot");

    std::cout << "\n=== Testing WhoAmI ===\n";
    diamond1.whoAmI();

    std::cout << "\n=== Destructors Called ===\n";
    return 0;
}
