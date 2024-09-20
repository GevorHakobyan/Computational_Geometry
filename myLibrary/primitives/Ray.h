#pragma once
#include "Point.h"
#include "Vector.h"

namespace geometry {
    class Ray {
        public: //methods
        explicit Ray(const Point&, const Vector&);
        Ray(const Ray&) noexcept;
        void setPoint(const Point&);
        void setDirection(const Vector&);
        const Point& getPoiont() const;
        const Vector& getDirection() const;

        private: //data members
        Point m_Point{};
        Vector m_Direction{};
    };
}; //namespace geometry