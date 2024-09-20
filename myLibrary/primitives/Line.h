#pragma once
#include "Vector.h"

namespace geometry {
    class Line {
        public:
        using Coordinates = std::tuple<float, float, float>;
        using Length = double;
        using Point = geometry::Vector;

        public:
        Line(const Vector&, const Vector&);
        Line(const Line&) noexcept;
        const Point& getP1() const;
        const Point& getP2() const;
        bool doesIntersectWith(const Line&) const; //need to check ??

        private:
        bool hasSameSign(const Vector&, const Vector&) const;

        private:
        Point m_P1;
        Point m_P2;
    };
    #include "Line.inl"
};//namespace geometry