#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    int dir_cpa = Point::cross(c, point, a);

    return (
        dir_cpa == Point::cross(a, point, b)
        && dir_cpa == Point::cross(b, point, c));
}
