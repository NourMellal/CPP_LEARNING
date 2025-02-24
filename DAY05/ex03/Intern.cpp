#include "Intern.hpp"

const char *Intern::NoFormMatchException::what() const throw() {
    return "NoFormMatchException";
}

Intern::Intern() : sform("home"), rrform("home"), ppform("home") {
    _form[0] = &sform;
    _form[1] = &rrform;
    _form[2] = &ppform;
}
Intern::Intern(const Intern& rhs) : sform(rhs.sform), rrform(rhs.rrform) , ppform(rhs.ppform) {
    _form[0] = &sform;
    _form[1] = &rrform;
    _form[2] = &ppform;
}
Intern &Intern::operator=(const Intern& rhs) {
    if (this != &rhs)
    {
        sform = rhs.sform;
        rrform = rhs.rrform;
        ppform = rhs.ppform;
    }
    return *this;
}
Form *Intern::makeForm(std::string formName, std::string targetName)
{
    for (int i = 0 ; i < 3 ; i++)
    {
        if (_form[i]->getName() == formName)
        {
            _form[i]->setTarget(targetName);
            return _form[i];
        }
    }
    throw NoFormMatchException();
}

Intern::~Intern() {}