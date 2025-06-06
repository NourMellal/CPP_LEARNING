#include "Serializer.hpp"


uintptr_t Serializer::serialize(t_Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}


t_Data* Serializer::deserialize(uintptr_t raw) 
{
    return (reinterpret_cast<t_Data*>(raw));
}

Serializer::Serializer()
{
}

Serializer::~Serializer()
{
}

Serializer::Serializer(Serializer const &rhs)
{
    *this = rhs;
}

Serializer &Serializer::operator=(Serializer const &rhs)
{
    (void)rhs;
    return *this;
}