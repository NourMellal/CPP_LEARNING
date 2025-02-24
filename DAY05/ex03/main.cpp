#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int main(int ac, char **av)
{

    if (ac != 2) {
        std::cout << "Usage : " << av[0] << " [ name of bureaucrat ]\n"; 
        return 0;
    }
    uint grade;
    std::cout << "Set your Bureaucrat grade.\n";
    std::cin >> grade;
    try {
        Intern intrn;
        Bureaucrat b(av[1], grade);
        Form *form;
    
        std::cout << "ShrubberyCreationForm\n";
        std::cout << "RobotomyRequestForm\n";
        std::cout << "PresidentialPardonForm\n";
        
        std::string formName;
        std::cout << "ENTER your desired form Name: ";
        std::cin >> formName;

        std::string targetName;
        std::cout << "ENTER your desired form Target: ";
        std::cin >> targetName;    

        form = intrn.makeForm(formName, targetName);

        std::string reply;
        std::cout << "Do you want to sign the form " << form->getName() << "? [y/n] : ";
        std::cin >> reply;
        if (reply == "y")
        {
            std::cout << "Bureaucrat : " << b << " will sign form : " << *form << '\n';
            b.signForm(*form);
        }

        std::cout << "Do you want to execute the form " << form->getName() << "? [y/n] : ";
        std::cin >> reply;
        if (reply == "y")
        {
            std::cout << "Bureaucrat : " << b << " will execute form : " << *form << '\n';
            b.exec_form(*form);
        }
    } catch (std::exception &e) {
        std::cout << "Catched from main " << e.what() << '\n';
    }
    return (0);
}