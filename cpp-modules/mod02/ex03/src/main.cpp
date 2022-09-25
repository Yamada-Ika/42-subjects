#include <iostream>

#include <cassert>
#include <cmath>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void) {
    assert(bsp(Point(0, 0), Point(5, 0), Point(2.5, 5), Point(2.5, 2.5)) == true);
    assert(bsp(Point(0, 0), Point(5, 0), Point(2.5, 5), Point(0, 0)) == false);
    assert(bsp(Point(0, 0), Point(5, 0), Point(2.5, 5), Point(0, 5)) == false);
    assert(bsp(Point(0, 0), Point(5, 0), Point(2.5, 5), Point(2.5, 5)) == false);
    assert(bsp(Point(0, 0), Point(5, 0), Point(2.5, 5), Point(1, 2)) == false);
    assert(bsp(Point(0, 0), Point(5, 0), Point(2.5, 5), Point(2, 0)) == false);
    assert(bsp(Point(0, 0), Point(5, 0), Point(2.5, 5), Point(3.5, 3)) == false);
    assert(bsp(Point(0, 0), Point(5, 0), Point(2.5, 5), Point(3.5, 2.9)) == true);

    assert(bsp(Point(-5, -5), Point(5, -5), Point(0, 5), Point(0, 0)) == true);
    assert(bsp(Point(-5, -5), Point(5, -5), Point(0, 5), Point(0, 5)) == false);
    assert(bsp(Point(-5, -5), Point(5, -5), Point(0, 5), Point(-1, -1)) == true);
    return 0;
}
