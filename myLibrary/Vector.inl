#include "Vector.h"

geometry::Vector::Vector(const Coordinate x, const Coordinate y, const Coordinate z)
: m_X{x}, m_Y{y}, m_Z{z}
{
    setLength(decideLength());
}


geometry::Vector::Vector(const Point& p1) 
: m_X{0.0}, m_Y{0.0}, m_Z{0.0}, m_length{0}
{
    const auto[x, y, z] = p1.getLocation();
    setX(x);
    setY(y);
    setZ(z);
    setLength(decideLength());
}

geometry::Vector::Vector(const Vector& rhs) noexcept
: Vector(rhs.getX(), rhs.getY(), rhs.getZ()) {} 

void geometry::Vector::setX(const Coordinate x) {
    m_X = x;
}

void geometry::Vector::setY(const Coordinate y) {
    m_Y = y;
}

void geometry::Vector::setZ(const Coordinate z) {
    m_Z = z;
}

void geometry::Vector::setLength(const Length length) {
    m_length = length;
}

geometry::Vector::Coordinate geometry::Vector::getX() const {
    return m_X;
}

geometry::Vector::Coordinate geometry::Vector::getY() const {
    return m_Y;
}

geometry::Vector::Coordinate geometry::Vector::getZ() const {
    return m_Z;
}

geometry::Vector::Coordinates geometry::Vector::getCoordinates() const {
    return {m_X, m_Y, m_Z};
}

geometry::Vector::Length geometry::Vector::getLength() const {
    return m_length;
}


geometry::Vector geometry::Vector::operator+(const Vector& rhs) const {
    Coordinate sumX = this->m_X + rhs.getX();
    Coordinate sumY = this->m_Y + rhs.getY();
    Coordinate sumZ = this->m_Z + rhs.getZ();
    return Vector{sumX, sumY, sumZ};
}

geometry::Vector geometry::Vector::operator-(const Vector& rhs) const {
    Coordinate sumX = this->m_X - rhs.getX();
    Coordinate sumY = this->m_Y - rhs.getY();
    Coordinate sumZ = this->m_Z + rhs.getZ();
    return Vector{sumX, sumY, sumZ};
}

void geometry::Vector::operator*(size_t value) {
    m_X *= value;
    m_Y *= value;
    m_Z *= value;

    setLength(decideLength());
}


geometry::Vector::Radian geometry::Vector::getAngle_With_Radian(const Vector& rhs) const {
    /* FORMULA USED: COS(theta) = (A.B) / (|A| * |B|) */
    Length LengthProduct = this->m_length * rhs.getLength();
    double dotProduct = this->operator*(rhs);
    Radian cos_theta = (dotProduct / LengthProduct);
    cos_theta = std::clamp(cos_theta, -1.0, 1.0);
    Radian theta = std::acos(cos_theta);
    return theta;
}

geometry::Vector::Degree geometry::Vector::getAngle_With_Degree(const Vector& rhs)  const {
    Radian theta = getAngle_With_Radian(rhs);
    return Radian_to_Degree(theta);
}

double geometry::Vector::operator*(const Vector& rhs) const {
    const auto[x, y, z] = rhs.getCoordinates();

    return ((m_X * x)  + (m_Y * y) + (m_Z * z));
}  

geometry::Vector geometry::Vector::operator^(const Vector& rhs) const{
    /* FORMULA USED: MATRIX DETERMINAN METHOD */
    auto[x1, y1, z1] = this->getCoordinates();
    auto[x2, y2, z2] = rhs.getCoordinates();

    Coordinate newX = ((y1 * z2) - (z1 * y2));
    Coordinate newY = ((x1 * z2) - (z1 * x2));
    Coordinate newZ = ((x1 * y2) - (y1 * x2));

    return Vector{newX, -newY, newZ};
}

bool geometry::Vector::operator==(const Vector& rhs) const {
    const auto[x, y, z] = rhs.getCoordinates();

    return ((m_X == x) && (m_Y == y) && (m_Z == z));
}

geometry::Vector geometry::Vector::ProjectionOn_Vector(const Vector& rhs) const {
    /* FORMULA USED: ((A.B / |B|^2) * B) */
    Radian angleWith_V = this->getAngle_With_Radian(rhs);
    double dotProduct = this->operator*(rhs);
    double ProjectionFactor = dotProduct / (std::pow(rhs.getLength(), 2));

    auto multiply = [ProjectionFactor](const auto& val) {return val * ProjectionFactor; };
    auto x = multiply(rhs.getX());
    auto y = multiply(rhs.getY());
    auto z = multiply(rhs.getZ());

    return Vector{x, y, z};
}

geometry::Vector geometry::Vector::Unit() const{
    auto x = m_X / std::abs(m_X);
    auto y = m_Y / std::abs(m_Y);
    auto z = m_Z / std::abs(m_Z);

    return Vector(x, y, z);
}

geometry::Vector::Length geometry::Vector::decideLength() const {
    auto X = m_X * m_X;
    auto Y = m_Y * m_Y;
    auto Z = m_Z *  m_Z;

    return std::sqrt(X + Y + Z);
}

geometry::Vector::Degree geometry::Vector::Radian_to_Degree(const Radian theta) const {
    //1Rad = 57.2958 degree
    return (57.2958 * theta);
}