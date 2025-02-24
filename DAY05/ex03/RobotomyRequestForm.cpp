#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : Form("RobotomyRequestForm", 45, 72), _target(target) 
{
    if (target.empty())
        throw EmptyTargetException();
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rhs) : Form(rhs), _target(rhs._target) {}
RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 45, 72), _target("default") {}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
    Form::operator=(rhs);
    this->_target = rhs._target;
    return *this;
}
RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::setTarget(std::string newTarget)
{
    if (newTarget.empty())
        throw EmptyTargetException();
    _target = newTarget;
}

void RobotomyRequestForm::beExecuted(const Bureaucrat &b)
{
    Form::beExecuted(b);
    std::cout << "Making some drilling noise.\n";
    std::cout << "..\n";
    srand(time(0));
    int random = rand() % 2;
    if (random) {
        std::cout << _target << " has been robotomized successfully.\n";
    } else {
        std::cout << "the robotomy for " << _target << " has failed.\n";
    }
}