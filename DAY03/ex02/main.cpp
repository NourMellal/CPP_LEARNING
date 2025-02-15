#include "FragTrap.hpp"

int main() {
    std::cout << "\n=== Creating FragTraps ===\n";
    FragTrap frag1("Fraggy");
    FragTrap frag2(frag1); // Copy constructor test
    FragTrap frag3;
    frag3 = frag1; // Copy assignment test

    std::cout << "\n=== Testing Attack ===\n";
    frag1.attack("Target Dummy");

    std::cout << "\n=== Taking Damage ===\n";
    frag1.takeDamage(30);
    
    std::cout << "\n=== Repairing ===\n";
    frag1.beRepaired(20);

    std::cout << "\n=== Testing High Fives ===\n";
    frag1.highFivesGuys();

    std::cout << "\n=== Destructors Called ===\n";
    return 0;
}
