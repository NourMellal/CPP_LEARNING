#include "Form.hpp"
#include "Bureaucrat.hpp"

const char *Form::GradeTooHighException::what() const throw()
{
    return "GradeTooHighException";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "GradeTooLowException";
}

const char *Form::EmptyNameException::what() const throw()
{
    return "EmptyNameException";
}

Form::Form( void ) : _name("Default"), _grade_to_exec(150), _grade_to_sign(150), _is_signed(false) {}

Form::Form(const std::string name, const uint grade_to_exec, const uint grade_to_sign) : _name(name), _grade_to_exec(grade_to_exec), _grade_to_sign(grade_to_sign), _is_signed(false)
{
    if (name.empty())
        throw EmptyNameException();
    if (grade_to_sign < 1 || grade_to_exec < 1)
        throw GradeTooHighException();
    if (grade_to_sign > 150 || grade_to_exec > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& rhs) : _name(rhs._name) , _grade_to_exec(rhs._grade_to_exec), _grade_to_sign(rhs._grade_to_sign), _is_signed(rhs._is_signed)
{
}

Form &Form::operator=(const Form& rhs)
{
    if (this != &rhs)
    {
        _is_signed = rhs._is_signed;
    }
    return *this;
}

Form::~Form()
{
}

uint Form::getExecGrade() const
{
    return (_grade_to_exec);
}

uint Form::getSignGrade() const
{
    return (_grade_to_sign);
}

bool Form::getIsSigned() const
{
    return (_is_signed);
}

std::string Form::getName() const
{
    return (_name);
}

void       Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > _grade_to_sign)
        throw GradeTooLowException();
    _is_signed = true;
    std::cout << "Bureaucrat " << b.getName() << " is succesfully signed the form " << this->getName() << "\n"; 
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    return (os << form.getName() << " form, signed: " << form.getIsSigned() << ", sign grade: " << form.getSignGrade() << ", exec grade: " << form.getExecGrade() << "\n");
}