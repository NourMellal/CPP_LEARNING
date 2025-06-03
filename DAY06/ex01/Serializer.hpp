#pragma once

#include "Data.hpp"
#include <iostream>
#include <stdint.h>


class Serializer {

    public:
        static uintptr_t serialize(t_Data* ptr);
        static t_Data* deserialize(uintptr_t raw);
    private:
        Serializer(Serializer const &rhs);
        Serializer();
        Serializer &operator=(Serializer const &rhs);
        ~Serializer();
};
