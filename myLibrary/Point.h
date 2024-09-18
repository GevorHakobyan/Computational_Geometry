#pragma one
#include <cstddef>
#include <utility>

namespace geometry {
    class Point {
        public://usings
        using Coordinate = double;
        using Location = std::pair<Coordinate, Coordinate>;

        public: //methods
        Point() = default; // Origin(0, 0)
        explicit Point(Coordinate, Coordinate);
        Point(const Point&) noexcept;
        ~Point() = default;
        //getters and setters
        void setX(Coordinate);
        void setY(Coordinate);
        Coordinate getX() const;
        Coordinate getY() const;
        Location getLocation() const;
        Point operator-(const Point&) const;

        private: //data members
        Coordinate m_X{};
        Coordinate m_Y{};
    };
}//namespace geometry