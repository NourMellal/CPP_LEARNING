#include <iostream>
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

void testBSP(const Point& A, const Point& B, const Point& C, const Point& P, bool expected) {
    bool result = bsp(A, B, C, P);
    std::cout << "Point (" << P.get_x().toFloat() << ", " << P.get_y().toFloat() << ") is ";
    std::cout << (result ? "inside" : "outside") << " the triangle. ";
    std::cout << (result == expected ? "✅" : "❌") << std::endl;
}

int main() {
    Point A(0, 0);
    Point B(5, 0);
    Point C(2.5, 5);

    Point inside(2.5, 2);
    Point outside(5, 5);
    Point edge(2.5, 0);
    Point vertex(0, 0);

    testBSP(A, B, C, inside, true);
    testBSP(A, B, C, outside, false);
    testBSP(A, B, C, edge, false);
    testBSP(A, B, C, vertex, false);

    return 0;
}
