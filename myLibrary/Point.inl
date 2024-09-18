#include "Point.h"

geometry::Point::Point(Coordinate x,  Coordinate y) 
: m_X{x}, m_Y{y} {};

geometry::Point::Point(const Point& rhs) {
    this->m_X = rhs.getX();
    this->m_Y = rhs.getY();
}

void geometry::Point::setX(Coordinate x) {
    m_X = x;
}

void geometry::Point::setY(Coordinate y) {
    m_Y = y;
}

geometry::Point::Coordinate geometry::Point::getX() const {
    return m_X;
}

geometry::Point::Coordinate geometry::Point::getY() const {
    return m_Y;
}

geometry::Point::Location geometry::Point::getLocation() const {
    return {m_X, m_Y};
}

geometry::Point geometry::Point::operator-(const Point& rhs) const {
    return Point(this->m_X - rhs.getX(), this->m_Y - rhs.getY());
}
