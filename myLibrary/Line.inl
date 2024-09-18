#include "Line.h"
#include "math.h"

geometry::Line::Line(const Point& p1, const Point& p2) 
: m_P1{p1}, m_P2{p2} {};

geometry::Line::Line(const Line& rhs) {
    this->m_P1 = rhs.getP1();
    this->m_P2 = rhs.getP2();
}

geometry::Line::Length geometry::Line::getLength() const {
    const auto newPoint{m_P2 - m_P1};//why operator- worked here after making it const??
    auto squareSum = std::pow(newPoint.getX(), 2) + std::pow(newPoint.getY(),2);
    return std::sqrt(squareSum);
}

const geometry::Point& geometry::Line::getP1() const {
    return m_P1;
}

const geometry::Point& geometry::Line::getP2() const {
    return m_P2;
}

void geometry::Line::setP1(const Point& p1) {
    m_P1 = p1;
}

void geometry::Line::setP2(const Point& p2) {
    m_P2 = p2;
}

bool geometry::Line::doesIntersect_With(const Line& rhs) const {
    const auto orientation1{getP1()};
    const auto orientation2{getP2()};
    const auto destination1{rhs.getP1()};
    const auto destination2{rhs.getP2()};

    const Vector O1_V1{orientation1, destination1};
    const Vector O1_V2{orientation1, destination2};
    const Vector O2_V1{orientation2, destination1};
    const Vector O2_V2{orientation2, destination2};

    const auto cross1{O1_V1^O1_V2};
    const auto cross2{O2_V1^O2_V2};

    return !hasSameSign(cross1.Unit(), cross2.Unit());
}

bool geometry::Line::hasSameSign(const Vector& v1, const Vector& v2) const {
    return v1.getY() == v2.getY();
}