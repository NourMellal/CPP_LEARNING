#include "Zombie.hpp"

Zombie *zombieHorde( int N, std::string name) {
    Zombie *zombie = new Zombie[N];
    if (N <= 0)
        return NULL ;
    for (int i = 0; i < N; i++)
        zombie[i].setZombieName(name);
    return zombie ;
}