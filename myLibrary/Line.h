#pragma once
#include "Vector.h"

namespace geometry {
    class Line {
        public:
        using Length = double;

        public: //methods
        explicit Line(const Point&, const Point&);
        Line(const Line&) noexcept;
        ~Line() = default;
        Length getLength() const; 
        //getters and setters
        const Point& getP1() const;
        const Point& getP2() const;
        void setP1(const Point&);
        void setP2(const Point&);

        public: //utility methods
        bool doesIntersect_With(const Line&) const;
        private: //helper methods
        bool hasSameSign(const Vector&, const Vector&) const;

        private: //data memebers
        Point m_P1{};
        Point m_P2{};
    };
};//namespace geometry