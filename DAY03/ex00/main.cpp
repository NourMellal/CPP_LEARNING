
#include "ClapTrap.hpp"

int main()
{
	std::cout << "\n=== Creating ClapTraps ===\n";
	ClapTrap clap1("Clappy");
	ClapTrap clap2("Trapster");
	ClapTrap clap3(clap1);
	ClapTrap clap4;
	clap4 = clap2;

	std::cout << "\n=== Testing Attacks ===\n";
	clap1.attack("Trapster");
	clap2.attack("Clappy");

	std::cout << "\n=== Taking Damage ===\n";
	clap1.takeDamage(3);
	clap2.takeDamage(5);
	clap1.takeDamage(10);

	std::cout << "\n=== Trying to Attack with 0 HP ===\n";
	clap1.attack("Trapster");

	std::cout << "\n=== Repairing ClapTraps ===\n";
	clap2.beRepaired(4);
	clap1.beRepaired(10);
	std::cout << "\n=== Destructors Called ===\n";
	return 0;
}
