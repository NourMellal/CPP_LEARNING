#pragma once

#include <string>
#include <iostream>
typedef unsigned int uint;

class Bureaucrat;

class Form
{
public:
    class GradeTooHighException : public std::exception
    {
        private:
        public:
            virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        private:
        public:
            virtual const char *what() const throw();
    };
    class EmptyNameException : public std::exception
    {
        private:
        public:
            virtual const char *what() const throw();
    };
    class FormNotSignedException : public std::exception
    {
        private:
        public:
            virtual const char *what() const throw();
    };
    class EmptyTargetException : public std::exception
    {
        private:
        public:
            virtual const char *what() const throw();
    };

private:
    const std::string _name;
    const uint        _grade_to_exec;
    const uint        _grade_to_sign;
    bool              _is_signed;
public:
    Form(const std::string name, const uint grade_to_exec, const uint grade_to_sign);
    Form(const Form& rhs);
    Form &operator=(const Form& rhs);
    virtual ~Form();
    Form( void );

    std::string getName() const;
    uint getExecGrade() const;
    uint getSignGrade() const;
    bool       getIsSigned() const;
    void       beSigned(const Bureaucrat &b);
    void virtual beExecuted(const Bureaucrat &b);
    void virtual setTarget(std::string newTarget) = 0;
};

std::ostream &operator<<(std::ostream &os, const Form &form);
