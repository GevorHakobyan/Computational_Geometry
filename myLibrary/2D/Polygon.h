#pragma once
#include "Vector.h"
#include <vector>
#include <stack>
#include <ranges>

//this class will be responsible to build minimum convex hull with a given set of points

namespace two_d {

class Polygon {
    public:
    using Point = geometry::Vector;
    using PointList = std::stack<Point>;
    using Coordinate = geometry::Vector::Coordinate;
    using Index = size_t;
    public:
    Polygon(std::vector<Point>&);
    ~Polygon() = default;
    private:
    Index findLowestY(std::vector<Point>&) const;
    void sort(std::vector<Point>&) const; //based on X axes
    void findMinPolygon(std::vector<Point>&);
    bool isClockwise(const Point&) const;
    void popToStopPoint(const Point&);
    void print(const std::vector<Point>&) const;
    private:
    PointList m_list{};
    };
    #include "Polygon.inl"
}; //namespace two_d