#include "Vector.h"
#include "Line.h"
#include <iostream>

int main() {

    geometry::Vector a2{3, 3, 0};
    geometry::Vector b2{5, 1, 0};
    geometry::Line l1{a2, b2};

    geometry::Vector a{5, 2, 0};
    geometry::Vector b{2, 2, 0};
    geometry::Line l2{a, b};
    std::cout << std::boolalpha << l1.doesIntersectWith(l2) << "\n";
}