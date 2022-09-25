#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point {
 private:
    const Fixed x;
    const Fixed y;

 public:
    Point(void);
    Point(float x, float y);
    Point(const Fixed &x, const Fixed &y);
    Point(const Point& other);
    ~Point(void);
    Point& operator=(const Point& other);
    Fixed& getX(void) const;
    Fixed& getY(void) const;
    static int cross(const Point &p1, const Point &center, const Point &p2);
    Point findVector(const Point &to) const;
};

std::ostream& operator<<(std::ostream& lhs, const Point& rhs);

#endif
