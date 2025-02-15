#include "ScavTrap.hpp"

int main() {
    std::cout << "\n=== Creating ScavTrap ===\n";
    ScavTrap scav1("Guardian");
    ScavTrap scav2(scav1); // Copy constructor test
    ScavTrap scav3;
    scav3 = scav1; // Copy assignment test

    std::cout << "\n=== Testing Attack ===\n";
    scav1.attack("Intruder");

    std::cout << "\n=== Testing Guard Mode ===\n";
    scav1.guardGate();

    std::cout << "\n=== Destructors Called ===\n";
    return 0;
}
