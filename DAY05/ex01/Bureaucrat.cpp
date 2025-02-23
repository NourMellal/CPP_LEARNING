#include "Bureaucrat.hpp"
#include "Form.hpp"

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "GradeTooHighException";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "GradeTooLowException";
}

const char *Bureaucrat::EmptyNameException::what() const throw()
{
    return "EmptyNameException";
}

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string name, uint grade) : _name(name)
{
    if (name.empty())
        throw EmptyNameException();
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;    
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& rhs)
{
    if (this != &rhs) {
        _grade  = rhs._grade;
    }
    return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat& rhs)
{
    *this = rhs;
}

std::string Bureaucrat::getName( void ) const
{
    return (this->_name);
}

uint Bureaucrat::getGrade( void ) const
{
    return (this->_grade);
}

void Bureaucrat::decrementGrade()
{
    if (_grade == 150)
        throw GradeTooLowException();
    _grade++;
}

void Bureaucrat::incrementGrade()
{
    if (_grade == 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
    }
    catch (std::exception &e)
    {
        std::cout << this->_name << " cannot sign " << form.getName() << " because: " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &br)
{
    os << br.getName() << ", bureaucrat grade " << br.getGrade() << "\n";
    return os;
}
