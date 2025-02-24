#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


class Intern {
public:
    class NoFormMatchException : public std::exception
    {
        private:
        public:
            virtual const char *what() const throw();
    };
private:
    ShrubberyCreationForm sform;
    RobotomyRequestForm rrform;
    PresidentialPardonForm ppform;
    Form *_form[3];

public:
    Intern();
    Intern(const Intern& rhs);
    Intern &operator=(const Intern& rhs);
    ~Intern();

    Form* makeForm(std::string formName, std::string targetName);
};