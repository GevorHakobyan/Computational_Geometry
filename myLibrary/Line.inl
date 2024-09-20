#include "Line.h"

geometry::Line::Line(const Vector& v1, const Vector& v2) 
: m_Coordinates{0.0, 0.0, 0.0}, 
  m_Length{0.0}, 
  m_P1{v1}, 
  m_P2{v2}
{
    const auto [x, y, z] = (v1 - v2).getCoordinates();
    setCoordinates(x, y, z);

    const auto[x1, y1, z1] = (v2 - v1).getCoordinates();
    setLength(x1, y1, z1);
}

geometry::Line::Line(const Line& rhs) {
    this->m_Coordinates = rhs.getCoordinates();
}

void geometry::Line::setCoordinates(const float x, const float y, const float z) {
    std::get<0>(m_Coordinates) = x;
    std::get<1>(m_Coordinates) = y;
    std::get<2>(m_Coordinates) = z;
}

geometry::Line::Coordinates geometry::Line::getCoordinates() const {
    return m_Coordinates;
}

void geometry::Line::setLength(float x, float y, float z) {
    auto X = x * x;
    auto Y = y * y;
    auto Z = z * z;

    m_Length = std::sqrt(X + Y + Z);
}

geometry::Line::Length geometry::Line::getLength() const {
    return m_Length;
}

const geometry::Line::Point& geometry::Line::getP1() const {
    return m_P1;
}

const geometry::Line::Point& geometry::Line::getP2() const {
    return m_P2;
}

bool geometry::Line::doesIntersectWith(const Line& rhs) const{
    const auto O1P1 = m_P1 - rhs.getP1();
    const auto O1P2 = m_P1 - rhs.getP2();
    const auto cross1 = O1P1 ^ O1P2;
    
    const auto O2P1 = m_P2 - rhs.getP1();
    const auto O2P2 = m_P2 - rhs.getP2();
    const auto cross2 = O2P1 ^ O2P2;

    return !hasSameSign(cross1, cross2);
}

bool geometry::Line::hasSameSign(const Vector& v1, const Vector& v2) const {
    return v1.Unit() == v2.Unit();
}

