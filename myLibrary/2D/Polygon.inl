#include "Polygon.h"
#include <iostream>

two_d::Polygon::Polygon(std::vector<Point>& list) {
    findMinPolygon(list);
}

two_d::Polygon::Index two_d::Polygon::findLowestY(std::vector<Point>& list) const {
    auto minElem = std::ranges::min_element(list, [](Point& a, Point& b) 
    {return a.getY() < b.getY();});

    return std::distance(list.begin(), minElem);
}

void two_d::Polygon::sort(std::vector<Point>& list) const{
    geometry::Vector X_axes{1, 0, 0};
    geometry::Vector::Radian minTheta;

    std::ranges::sort(list, [&](const Point a, const Point b) {
    return a.getAngle_With_Radian(X_axes) < b.getAngle_With_Radian(X_axes);});
    //print(list);
}

void two_d::Polygon::findMinPolygon(std::vector<Point>& list) {
    sort(list);
    Index minY = findLowestY(list);
    //print(list);

    m_list.push(list[minY]);
    auto stopPoint = list[minY];
    list.erase(std::remove(list.begin(), list.end(), list[minY]), list.end());
    m_list.push(list[0]);

    //print(list);


    for (size_t i{1}; i < list.size(); ++i) {
        auto cross = m_list.top() ^ list[i];

        if (!isClockwise(cross)) {
            m_list.push(list[i]);
        } else {
            popToStopPoint(stopPoint);
            m_list.push(list[i]);
            stopPoint = list[i];
       }

    }

    while(!m_list.empty()) {
        m_list.top().printCoordinates();
        m_list.pop();
    }
}

bool two_d::Polygon::isClockwise(const Point& v1) const {
    auto X = v1.getX();
    auto Y = v1.getY();

    return ((X - Y) >= 0);
}

void two_d::Polygon::popToStopPoint(const Point& stopPoint) {
    auto tmp = m_list.top();
    while (tmp != stopPoint) {
        m_list.pop();
        tmp = m_list.top();
    }
}

void two_d::Polygon::print(const std::vector<Point>& rhs) const {
    for (const auto& elem : rhs) {
        elem.printCoordinates();
    }
    std::cout << "\n";
}