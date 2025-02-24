#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public Form
{
private:
    std::string _target;
public:
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm &rhs);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
    ~RobotomyRequestForm();

    void beExecuted(const Bureaucrat &b);
};
