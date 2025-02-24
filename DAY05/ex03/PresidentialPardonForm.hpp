#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public Form
{
private:
    std::string _target;
public:
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm &rhs);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
    ~PresidentialPardonForm();

    void beExecuted(const Bureaucrat &b);
    void setTarget(std::string newTarget);
};
