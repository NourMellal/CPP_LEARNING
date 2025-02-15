#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{

private:
    std::string name;

public:
    Zombie(std::string name);
    Zombie( );
    ~Zombie( );

    /* I think this is a getter so it could be const :D*/
    void announce( void ) const;
    void setZombieName( std::string name );

};

void randomChump( std::string name );
Zombie* zombieHorde( int N, std::string name );
Zombie* newZombie( std::string name );

#endif