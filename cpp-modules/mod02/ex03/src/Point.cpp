#include "Point.hpp"

#include <iostream>
#include <cmath>

Point::Point(void) : x(Fixed(0)), y(Fixed(0)) {}

Point::Point(float x, float y) : x(Fixed(x)), y(Fixed(y)) {}

Point::Point(const Fixed &x, const Fixed &y) : x(x), y(y) {}

Point::Point(const Point& other) {
    *this = other;
}

Point::~Point(void) {}

Point& Point::operator=(__attribute__((unused)) const Point& other) {
    return *this;
}

Fixed& Point::getX(void) const {
    return const_cast<Fixed &>(x);
}

Fixed& Point::getY(void) const {
    return const_cast<Fixed &>(y);
}

Point Point::findVector(const Point &to) const {
    return Point(to.getX() - this->getX(), to.getY() - this->getY());
}

int Point::cross(const Point &p1, const Point &center, const Point &p2) {
    Point c_to_p1 = center.findVector(p1);
    Point c_to_p2 = center.findVector(p2);

    Fixed dir = c_to_p1.getX() * c_to_p2.getY() - c_to_p1.getY() * c_to_p2.getX();

    if (dir > Fixed(0))
        return 1;
    if (dir == Fixed(0))
        return 0;
    return -1;
}

std::ostream& operator<<(std::ostream& lhs, const Point& rhs) {
    lhs << "x : ";
    lhs << rhs.getX();
    lhs << " ";
    lhs << "y : ";
    lhs << rhs.getY();
    return lhs;
}
