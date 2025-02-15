#include "MateriaSource.hpp"


MateriaSource::MateriaSource() : materias() {

}

MateriaSource::~MateriaSource() {
    for (int i = 0 ; i < 4; i++) {
        delete materias[i];
    }
}
MateriaSource::MateriaSource(const MateriaSource &rhs) : IMateriaSource(rhs) {
    for (int i = 0; i < 4 ; i++) {
        materias[i] = rhs.materias[i] ? rhs.materias[i]->clone() : NULL;
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs) {
    if (this != &rhs)
    {
        
        for (int i = 0; i < 4; i++) {
            delete materias[i];
            materias[i] = rhs.materias[i] ? rhs.materias[i]->clone() : NULL;
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i < 4; i++) {
        if (!materias[i]) {
            std::cout << "Learned a materia type " << m->getType() << '\n';
            materias[i] = m;
            return ;
        }
    }
    if (m)
        delete m;
    std::cerr << "No more free slots in Inventory to learn a new materia" << std::endl; 
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (materias[i] && materias[i]->getType() == type) {
            return materias[i]->clone();
        }
    }
    std::cerr << "Materia of type" << type << " is unknown." << std::endl;
    return NULL;
}