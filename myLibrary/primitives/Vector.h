#pragma once
#include <algorithm>
#include "Point.h"
#include "tuple"
#include <utility>

namespace geometry {
    class Vector {
    public://usings
    using Coordinate = float;
    using Coordinates = std::tuple<Coordinate, Coordinate, Coordinate>;
    using Radian = double;
    using Length = double;
    using Degree = double;

    public:
    enum class AngleType{Acute = 1, Right, Obtuse};

    public: //methods
    Vector() = default; // unit vector(1, 0) on Y
    explicit Vector(const Coordinate, const Coordinate, const Coordinate);
    explicit Vector(const Point&);
    ~Vector() = default;
    Vector(const Vector&) noexcept;
    //getters and setters
    void setX(const Coordinate);
    void setY(const Coordinate);
    void setZ(const Coordinate);
    void setLength(const Length);
    Coordinate getX() const;
    Coordinate getY() const;
    Coordinate getZ() const;
    Coordinates getCoordinates() const;
    Length getLength() const;

    public: //utility methods
    Vector& operator=(const Vector&) noexcept;
    Vector operator+(const Vector&) const;
    Vector operator-(const Vector&) const;
    void operator*(size_t); //stretch or contract
    double operator*(const Vector&) const;
    Vector operator^(const Vector&) const;
    bool operator==(const Vector&) const;
    Radian getAngle_With_Radian(const Vector&) const;
    Degree getAngle_With_Degree(const Vector&) const;
    Vector ProjectionOn_Vector(const Vector&) const;
    Vector Unit() const;

    private: //helper methods
    Degree Radian_to_Degree(const Radian) const;
    Length decideLength() const;
    void Swap(Vector&, Vector&);

    private: //data members
    Coordinate m_X{};
    Coordinate m_Y{1};
    Coordinate m_Z{};
    Length m_length{1};
    };

    #include "Vector.inl"
}; //namespace geometry