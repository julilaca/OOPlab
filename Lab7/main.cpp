#include <iostream>
#include "tree.h"

int main() {
    float a = 300.0_Kelvin;
    float b = 120.0_Fahrenheit;
    std::cout << a << " " << b << "\n";

    Tree<int> tree;
    auto root = tree.add_node(10);
    tree.add_node(20, root);
    tree.add_node(30, root);
    std::cout << tree.count();
    return 0;
}