#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : Form("PresidentialPardonForm", 5, 25), _target(target) 
{
    if (target.empty())
        throw EmptyTargetException();
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &rhs) : Form(rhs), _target(rhs._target) {}
PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 5, 25), _target("default") {}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
    Form::operator=(rhs);
    this->_target = rhs._target;
    return *this;
}
PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::beExecuted(const Bureaucrat &b)
{
    Form::beExecuted(b);
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox.\n";
}