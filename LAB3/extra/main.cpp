#include "Math.h"
#include "Canvas.h"
#include <iostream>

int main() {
    std::cout << "Add(2, 3): " << Math::Add(2, 3) << '\n';
    std::cout << "Add(2, 3, 4): " << Math::Add(2, 3, 4) << '\n';
    std::cout << "Add(2.5, 3.5): " << Math::Add(2.5, 3.5) << '\n';
    std::cout << "Add(2.5, 3.5, 4.5): " << Math::Add(2.5, 3.5, 4.5) << '\n';
    std::cout << "Mul(2, 3): " << Math::Mul(2, 3) << '\n';
    std::cout << "Mul(2, 3, 4): " << Math::Mul(2, 3, 4) << '\n';
    std::cout << "Mul(2.5, 3.5): " << Math::Mul(2.5, 3.5) << '\n';
    std::cout << "Mul(2.5, 3.5, 4.5): " << Math::Mul(2.5, 3.5, 4.5) << '\n';
    std::cout << "Add variadic (4 + 5 + 6): " << Math::Add(3, 4, 5, 6) << '\n';

    char* concat = Math::Add("Hello, ", "world!");
    if (concat) {
        std::cout << "String Add: " << concat << '\n';
        delete[] concat;
    } else {
        std::cout << "Null string input.\n";
    }

    Canvas canvas(10, 50);
    canvas.set_pixels(4, 4, 25, 124, 3, 33, 124, 2, 24, 95, 4, 3, 95);
    canvas.print();

    return 0;
}
