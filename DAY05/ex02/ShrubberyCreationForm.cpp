#include "ShrubberyCreationForm.hpp"
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : Form("ShrubberyCreationForm", 137, 145), _target(target) 
{
    if (target.empty())
        throw EmptyTargetException();
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &rhs) : Form(rhs), _target(rhs._target) {}
ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 137, 145), _target("default") {}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
    Form::operator=(rhs);
    this->_target = rhs._target;
    return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::beExecuted(const Bureaucrat &b)
{
    Form::beExecuted(b);
    std::ofstream shruberry;
    shruberry.open((_target + "_shruberry").c_str());
    if (!shruberry.fail())
    {
        shruberry << TREE_CSTR;
        shruberry.close();
        std::cout << b.getName() << " succesfully created a shruberry\n"; 
    } else {
        std::cerr << "can't open this file :( \n";
    }
}