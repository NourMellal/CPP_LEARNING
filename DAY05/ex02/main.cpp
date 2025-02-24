#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main(int ac, char **av)
{

    if (ac != 3) {
        std::cout << "Usage : " << av[0] << " [ name of bureaucrat ] [Name of target ]\n"; 
        return 0;
    }
    uint grade;
    std::cout << "Set your Bureaucrat grade.\n";
    std::cin >> grade;
    try {
    
        Bureaucrat b(av[1], grade);
        ShrubberyCreationForm sf = ShrubberyCreationForm(av[2]);
        RobotomyRequestForm rf = RobotomyRequestForm(av[2]);
        PresidentialPardonForm pf = PresidentialPardonForm(av[2]);
    
        Form *form;
        rechoose:
        std::cout << "1: ShrubberyCreationForm\n";
        std::cout << "2: RobotomyRequestForm\n";
        std::cout << "3: PresidentialPardonForm\n";
    
        std::cout << "ENTER your desired form: ";
        std::cin >> grade;
    
        switch (grade)
        {
        case 1:
            form = &sf;
            break;
        case 2:
            form = &rf;
            break;
        case 3:
            form = &pf;
            break;
        default:
            std::cout << "Wrong input\n";
            goto rechoose;
            break;
        }
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