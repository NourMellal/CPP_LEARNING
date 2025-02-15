#include "Zombie.hpp"

int main( void ) {
    Zombie *heapZmb = newZombie("Heap");
    heapZmb->announce();

    randomChump("StackZombie");

    return (0);
}