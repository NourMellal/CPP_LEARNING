#include <iostream>
#include "Fixed.hpp"

void testComparisonOperators() {
    std::cout << "\n=== Testing Comparison Operators ===" << std::endl;
    Fixed a(5.25f);
    Fixed b(10.5f);

    std::cout << "a: " << a << ", b: " << b << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;
}

void testArithmeticOperators() {
    std::cout << "\n=== Testing Arithmetic Operators ===" << std::endl;
    Fixed a(3.5f);
    Fixed b(2.0f);

    std::cout << "a: " << a << ", b: " << b << std::endl;
    std::cout << "a + b: " << (a + b) << std::endl;
    std::cout << "a - b: " << (a - b) << std::endl;
    std::cout << "a * b: " << (a * b) << std::endl;
    std::cout << "a / b: " << (a / b) << std::endl;

    // Edge case: division by zero
    Fixed zero(0);
    std::cout << "a / 0: ";
    std::cout << (a / zero) << std::endl; // Should handle gracefully
}

void testIncrementDecrement() {
    std::cout << "\n=== Testing Increment/Decrement Operators ===" << std::endl;
    Fixed a;

    std::cout << "Initial a: " << a << std::endl;
    std::cout << "a++: " << a++ << " (before increment)" << std::endl;
    std::cout << "After a++: " << a << std::endl;
    std::cout << "++a: " << ++a << " (after increment)" << std::endl;
    std::cout << "a--: " << a-- << " (before decrement)" << std::endl;
    std::cout << "After a--: " << a << std::endl;
    std::cout << "--a: " << --a << " (after decrement)" << std::endl;
}

void testMinMax() {
    std::cout << "\n=== Testing Min/Max Functions ===" << std::endl;
    Fixed a(3.75f);
    Fixed b(7.25f);

    std::cout << "a: " << a << ", b: " << b << std::endl;
    std::cout << "Min(a, b): " << Fixed::min(a, b) << std::endl;
    std::cout << "Max(a, b): " << Fixed::max(a, b) << std::endl;
}

int main() {
    testComparisonOperators();
    testArithmeticOperators();
    testIncrementDecrement();
    testMinMax();
    return 0;
}
