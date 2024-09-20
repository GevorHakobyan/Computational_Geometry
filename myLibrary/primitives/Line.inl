#include "Line.h"

geometry::Line::Line(const Vector& v1, const Vector& v2) 
: m_P1{v1}, m_P2{v2} {}

geometry::Line::Line(const Line& rhs) noexcept {
    this->m_P1 = rhs.getP1();
    this->m_P2 = rhs.getP2();
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

