#include <iostream>
#include "Polygon.h"

int main() {

    geometry::Vector a2{1, 1, 0};
    geometry::Vector b2{3, 2, 0};
    geometry::Vector a{4, 5, 0};
    geometry::Vector b{6, 1, 0};
    geometry::Vector d{2, 3, 0};
    std::vector<geometry::Vector> v1;
    v1.push_back(a2);
    v1.push_back(b2);
    v1.push_back(a);
    v1.push_back(b);
    v1.push_back(d);

    two_d::Polygon p{v1};
}