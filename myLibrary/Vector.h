#pragma once
#include "Point.h"

namespace geometry {
    class Vector {
    public://usings
    using Coordinate = double;
    using Orientation = std::pair<Coordinate, Coordinate>;
    using Radian = size_t;
    using Length = size_t;

    public:
    enum class AngleType{Acute = 1, Right, Obtuse};

    public: //methods
    Vector() = default; // unit vector(1, 0) on Y
    explicit Vector(Coordinate, Coordinate);
    explicit Vector(const Point&);
    explicit Vector(const Point&, const Point&);
    ~Vector() = default;
    Vector(const Vector&) noexcept;
    //getters and setters
    void setX(const Coordinate);
    void setY(const Coordinate);
    void setOriention(const Orientation);
    void SetLength(const Length);
    void setAngle(const Radian);
    Coordinate getX() const;
    Coordinate getY() const;
    Orientation getOrientation() const;
    Length getlength() const;
    Radian getAngle() const;

    public: //utility methods
    Vector&& operator+(const Vector&);
    Vector&& operator-(const Vector&);
    void operator*(size_t); //stretch or contract
    Radian getAngle_With(const Vector&) const;
    AngleType getAngleType(const Vector&) const;
    double operator*(const Vector&);
    Vector operator^(const Vector&) const;
    Vector ProjectionOn_X();
    Vector ProjectionOn_Y();
    Vector Unit() const;

    private: //data members
    Coordinate m_X{};
    Coordinate m_Y{1};
    Radian m_angle{90}; //angle with X
    Length m_length{1};
    Orientation m_oriention{0.0, 0.0};
    };
}; //namespace geometry