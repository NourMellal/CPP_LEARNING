#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <climits>
#include <cfloat>



// Constructor
ScalarConverter::ScalarConverter() {
    // Default constructor
}

// Destructor
ScalarConverter::~ScalarConverter() {
}

// Copy Constructor
ScalarConverter::ScalarConverter(const ScalarConverter &rhs) {
    *this = rhs;
}

// Copy Assignment Operator
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) {
    (void)rhs;
    return *this;
}
    
static void    convertChar(const std::string &s) {
        std::cout << "Convert Char\n";
        if (std::isprint(s[0]) && std::isdigit(s[0]) == 0)
        {
            std::cout << "char: " << s[0] << "\n";
            std::cout << "int: " << static_cast<int>(s[0]) << "\n";
            std::cout << "float: " << std::setprecision(1) << static_cast<float>(s[0]) << "f\n";
            std::cout << "double: " << std::setprecision(1) << static_cast<double>(s[0]) << "\n";
        }
        else
        {
            std::cout << "char: Non displayable\n";
	    	std::cout << "int: " << atoi(s.c_str()) << '\n';
	    	std::cout << "float: " << std::fixed << std::setprecision(1) << atof(s.c_str()) << "f\n";
	    	std::cout << "double: " << std::fixed << std::setprecision(1) << atof(s.c_str()) << '\n';
        }
}

static void convertInt(const std::string &s) {
    std::cout << "DEBUG: Converting INT: " << s << std::endl;


    double val = strtod(s.c_str(), NULL);
    if (val <= INT_MAX && val >= INT_MIN)
    {
        if (val >= ' ' && val <= '~')
        {
            std::cout << "char: " << static_cast<char>(val) << std::endl;
        }
        else if (val <= 127)
            std::cout << "Non Displayable!\n";
        else
            std::cout << "char: Impossible!\n";
        std::cout << "int: " << static_cast<int>(val) << std::endl;
    }
    else
    {
        std::cout << "char: Impossible!\n";

        if (val == INFINITY || val == -INFINITY || val == NAN)
        {
            std::cout << "int: Impossible!" << std::endl;
        }
        else
            std::cout << "int: Overflow!" << std::endl;
    }
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(val) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(val) << std::endl;
} 

static void convertFloat(const std::string &s) {
    std::cout << "DEBUG: Converting FLOAT: " << s << std::endl;
    


    double val = strtod(s.c_str(), NULL);
    if (val <= INT_MAX && val >= INT_MIN)
    {
        if (val >= ' ' && val <= '~')
        {
            std::cout << "char: " << static_cast<char>(val) << std::endl;
        }
        else if (val <= 127)
            std::cout << "Non Displayable!\n";
        else
            std::cout << "char: Impossible!\n";
        std::cout << "int: " << static_cast<int>(val) << std::endl;
    }
    else
    {
        std::cout << "char: Impossible!\n";

        if (val == INFINITY || val == -INFINITY || val == NAN)
        {
            std::cout << "int: Impossible!" << std::endl;
        }
        else
            std::cout << "int: Overflow!" << std::endl;
    }
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(val) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(val) << std::endl;
}

static void convertDouble(const std::string &s) {
    std::cout << "DEBUG: Converting DOUBLE: " << s << std::endl;
    


    double val = strtod(s.c_str(), NULL);
    if (val <= INT_MAX && val >= INT_MIN)
    {
        if (val >= ' ' && val <= '~')
        {
            std::cout << "char: " << static_cast<char>(val) << std::endl;
        }
        else if (val <= 127)
            std::cout << "char: Non Displayable!\n";
        else
            std::cout << "char: Impossible!\n";
        std::cout << "int: " << static_cast<int>(val) << std::endl;
    }
    else
    {
        std::cout << "char: Impossible!\n";

        if (val == INFINITY || val == -INFINITY || val == NAN)
        {
            std::cout << "int: Impossible!" << std::endl;
        }
        else
            std::cout << "int: Overflow!" << std::endl;
    }
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(val) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(val) << std::endl;
}

static void parse_string(std::string &s) {
    
    size_t      i = 0;
    bool        has_dec_point = false;

    for (; i < s.length(); i++)
    {
        if (s[i] == '-' || s[i] == '+')
        {
            if (i != 0)
            {
                std::cout << "Bad Input.\n"; /* 1.25*/
                return ;
            }
        }
        else if (s[i] == '.' && i > 0 && std::isdigit(s[i - 1]))
        {
            if (has_dec_point)
            {
                std::cout << "Bad Input.\n"; /* 1.25*/
                return ;
            }
            has_dec_point = true;
        }
        else if (std::isdigit(s[i]) == false)
            break;
    }

    if (i != s.length())
    {
        if (s == "inf" || s == "+inf" || s == "-inf" || s == "nan")
        {
            convertDouble(s);
        }
        else if (s == "inff" || s == "+inff" || s == "-inff" || s == "nanf")
        {
            convertFloat(s);
        }
        else if (s[i] == 'f' && i == s.length() - 1 && i > 0 && std::isdigit(s[i - 1])) {
            convertFloat(s);
        }
        else {
            std::cout << "DEBUG: Unrecognized format at position " << i << ": " << s << std::endl;
        }
    }
    else
    {
        if (i == 0 || std::isdigit(s[i - 1]) == false)
        {
            std::cout << "Bad Input.\n"; /* 1.25*/
            return ;    
        }
        if (has_dec_point)
        {
            convertDouble(s);
        }
        else
            convertInt(s);
    }
}



void  ScalarConverter::convert(const std::string &input) {
    if (input.empty()) {
        std::cout << "Empty input provided!\n";
    }
    else if (input.length() == 1) {
        convertChar(input);
    }
    else {
        std::string mutable_input = input;
        parse_string(mutable_input);
    }
}