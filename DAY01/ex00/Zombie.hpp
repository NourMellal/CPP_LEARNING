#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{

private:
    std::string name;

public:
    Zombie(std::string name);
    ~Zombie( );

    /* I think this is a getter so it could be const :D*/
    void announce( void ) const;
};

void randomChump( std::string name );
Zombie* newZombie( std::string name );

#endif