#include "Serializer.hpp"

int main(void) {

    t_Data d = {10, 5, 'a', false};
    // d.x = 10;
    // d.y = 5;
    // d.c = 'a';
    // d.b = false;

    int *ip = reinterpret_cast<int *>(&d);
    std::cout << *ip << std::endl;
    ip++;
    std::cout << *ip << std::endl;
    ip++;

    char *ch = reinterpret_cast<char *>(ip);
    std::cout << *ch << std::endl;
    ch++;
    bool *n = reinterpret_cast<bool*>(ch);
    std::cout << *n << std::endl;
    *n =  true;
    std::cout << *(reinterpret_cast<bool *>(ch)) << std::endl;

    uintptr_t p = Serializer::serialize(&d);
    t_Data *res = Serializer::deserialize(p);

        std::cout << "res->int = " << res->x << "\nres->int = " << res->y
        << "\nres->char = " << res->c << "\nres->bool = " << res->b << '\n';
    return 0;
}