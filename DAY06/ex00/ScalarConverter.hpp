#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <limits>
#include <stdexcept>



    
class ScalarConverter {
    
    public:
        static void convert(const std::string &input);
    
    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &rhs);
        ScalarConverter &operator=(const ScalarConverter &rhs);
};    

#endif // SCALARCONVERTER_HPP