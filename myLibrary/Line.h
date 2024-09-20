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
        void setCoordinates(const float, const float, const float);
        void setLength(float,float,float);
        Length getLength() const;
        Coordinates getCoordinates() const;
        const Point& getP1() const;
        const Point& getP2() const;

        private:
        bool doesIntersectWith(const Line&) const;
        bool hasSameSign(const Vector&, const Vector&) const;

        private:
        Coordinates m_Coordinates{};
        Length m_Length{};
        Point m_P1;
        Point m_P2;
    };
};//namespace geometry