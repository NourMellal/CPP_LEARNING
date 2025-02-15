#pragma once

#include <string>
#include <iostream>

class Brain {
    private:
        std::string ideas[100];

    public:
        ~Brain();
        Brain(const std::string &idea);
        Brain(const Brain &rhs);
        Brain &operator=(const Brain &rhs);
};