#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
    /* Valid case */
    
    try {
        Bureaucrat a = Bureaucrat("Aname", 50);
        Form       af = Form("Aform", 30, 60);
        a.signForm(af);
        std::cout << a;
        std::cout << af;
    } catch (std::exception &e) {
        std::cout << "main catched : " << e.what() << "\n";
    }

    std::cout << "\n\n===========================\n\n";

    /* Invalid case */
    try {
    Bureaucrat b = Bureaucrat("Bname", 50);
    Form       bf = Form("bform", 30, 49);
    b.signForm(bf);
    std::cout << b;
    std::cout << bf;
    } catch (std::exception &e) {
        std::cout << "main catched : " << e.what() << "\n";
    }
    return (0);
}