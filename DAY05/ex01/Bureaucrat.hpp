#pragma once

#include <string>
#include <iostream>


typedef unsigned int uint;

class Form;

class Bureaucrat
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

private:
    const std::string   _name;
    uint                _grade;
public:
    Bureaucrat();
    Bureaucrat(const std::string name, uint grade);
    Bureaucrat(const Bureaucrat& rhs);
    Bureaucrat &operator=(const Bureaucrat& rhs);
    ~Bureaucrat();

    std::string getName( void ) const ;
    uint getGrade( void ) const ;
    void incrementGrade();
    void decrementGrade();

    void signForm(Form &form);
};


std::ostream &operator<<(std::ostream &os, const Bureaucrat &br);