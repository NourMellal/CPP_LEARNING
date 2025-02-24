#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

#define TREE_CSTR \
"  *\n"\
" ***\n"\
"*****\n"\
"  |\n"

class ShrubberyCreationForm : public Form
{
private:
    std::string _target;
public:
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &rhs);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
    ~ShrubberyCreationForm();

    void beExecuted(const Bureaucrat &b);
    void setTarget(std::string newTarget);
};
