#pragma once
#include <cstddef>
#include <tuple>
#include "math.h"

namespace geometry {
    class Point {
        public://usings
        using Coordinate = float;
        using Location = std::tuple<Coordinate, Coordinate, Coordinate>;

        public: //methods
        Point() = default; // Origin(0, 0)
        explicit Point(Coordinate, Coordinate, Coordinate);
        Point(const Point&) noexcept;
        ~Point() = default;
        //getters and setters
        void setX(Coordinate);
        void setY(Coordinate);
        void setZ(Coordinate);
        Coordinate getX() const;
        Coordinate getY() const;
        Coordinate getZ() const;
        Location getLocation() const;
        Point operator-(const Point&) const;

        private: //data members
        Coordinate m_X{};
        Coordinate m_Y{};
        Coordinate m_Z{};
    };
    #include "Point.inl"
}//namespace geometry