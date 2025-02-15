#ifndef MATERIALSOURCE_HPP
#define MATERIALSOURCE_HPP

#include "IMateriaSource.hpp"


class MateriaSource : public IMateriaSource
{
    private:
        AMateria *materias[4];
    public:
        MateriaSource();
        ~MateriaSource();
        MateriaSource(const MateriaSource &rhs);
        MateriaSource &operator=(const MateriaSource &rhs);
        AMateria* createMateria(std::string const & type);
        void learnMateria(AMateria*);
};

#endif