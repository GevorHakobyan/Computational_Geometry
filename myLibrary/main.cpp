#include "Vector.h"
#include <iostream>

int main() {
    geometry::Vector a{3, 4, 0};
    geometry::Vector b{1, 2, 0};
    std::cout << a.ProjectionOn_Vector(b).getX() << "\n";
}