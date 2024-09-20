#include "Point.h"

geometry::Point::Point(Coordinate x,  Coordinate y, Coordinate z) 
: m_X{x}, m_Y{y}, m_Z{z} {};

geometry::Point::Point(const Point& rhs) noexcept {
    this->m_X = rhs.getX();
    this->m_Y = rhs.getY();
    this->m_Z = rhs.getZ();
}

void geometry::Point::setX(Coordinate x) {
    m_X = x;
}

void geometry::Point::setY(Coordinate y) {
    m_Y = y;
}

void geometry::Point::setZ(Coordinate z) {
    m_Z = z;
}
geometry::Point::Coordinate geometry::Point::getX() const {
    return m_X;
}

geometry::Point::Coordinate geometry::Point::getY() const {
    return m_Y;
}

geometry::Point::Coordinate geometry::Point::getZ() const {
    return m_Z;
}
geometry::Point::Location geometry::Point::getLocation() const {
    return {m_X, m_Y, m_Z};
}

geometry::Point geometry::Point::operator-(const Point& rhs) const {
    return Point(this->m_X - rhs.getX(), this->m_Y - rhs.getY(), this->m_Z - rhs.getZ());
}
