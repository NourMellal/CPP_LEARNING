#include "Zombie.hpp"

int main( void )
{
    int N = 8;
    std::string name = "Hamza" ;
    Zombie *zmb = zombieHorde(N , name ) ;
    if (zmb) {
        for (int i = 0 ; i < N; i++) {
            zmb[i].announce() ;
        }
    }
    delete[] zmb ;
    return 0;
}
