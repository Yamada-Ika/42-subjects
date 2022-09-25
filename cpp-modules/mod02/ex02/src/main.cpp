#include <iostream>
#include <iomanip>
#include <sstream>
#include <cassert>

#include "Fixed.hpp"

template <typename T> T Add(T x, T y) {return x + y;}
template <typename T> T Sub(T x, T y) {return x - y;}
template <typename T> T Mul(T x, T y) {return x * y;}
template <typename T> T Div(T x, T y) {return x / y;}

template <typename T>
void print(T n) {
    std::cout << std::fixed << n << std::endl;
}

template <typename T1, typename Func1, typename T2, typename Func2>
void comp(T1 float1, T1 float2, Func1 op_float, T2 fixed1, T2 fixed2, Func2 op_fixed, int line) {
    std::stringstream ss_float;
    ss_float << std::fixed << op_float(float1, float2);
    std::stringstream ss_fixed;
    ss_fixed << std::fixed << op_fixed(fixed1, fixed2);

    std::cout << "float with fixed point rep. : " << ss_float.str() << std::endl;
    std::cout << "my fixed point              : " << ss_fixed.str() << std::endl;

    if (ss_float.str() != ss_fixed.str()) {
        std::cout << "faile case : expected " << ss_float.str() << " but got " << ss_fixed.str() << std::endl;
        std::cout << "  line : " << line << std::endl;
    }
    assert(ss_float.str() == ss_fixed.str());
}

void originalTest(void) {

    std::cout << std::endl;
    comp(0.0f, 0.0f, &Add<float>, Fixed(0.0f), Fixed(0.0f), &Add<Fixed>, __LINE__);
    comp(0.00390625f, 0.0f, &Add<float>, Fixed(0.00390625f), Fixed(0.0f), &Add<Fixed>, __LINE__);
    comp(0.0078125f, 0.0f, &Add<float>, Fixed(0.0078125f), Fixed(0.0f), &Add<Fixed>, __LINE__);
    comp(0.015625f, 0.0f, &Add<float>, Fixed(0.015625f), Fixed(0.0f), &Add<Fixed>, __LINE__);
    comp(0.03125f, 0.0f, &Add<float>, Fixed(0.03125f), Fixed(0.0f), &Add<Fixed>, __LINE__);
    comp(0.0625f, 0.0f, &Add<float>, Fixed(0.0625f), Fixed(0.0f), &Add<Fixed>, __LINE__);
    comp(0.125f, 0.0f, &Add<float>, Fixed(0.125f), Fixed(0.0f), &Add<Fixed>, __LINE__);
    comp(0.25f, 0.0f, &Add<float>, Fixed(0.25f), Fixed(0.0f), &Add<Fixed>, __LINE__);
    comp(0.5f, 0.0f, &Add<float>, Fixed(0.5f), Fixed(0.0f), &Add<Fixed>, __LINE__);
    comp(1.0f, 0.0f, &Add<float>, Fixed(1.0f), Fixed(0.0f), &Add<Fixed>, __LINE__);
    comp(0.0f, 0.00390625f, &Add<float>, Fixed(0.0f), Fixed(0.00390625f), &Add<Fixed>, __LINE__);
    comp(0.0f, 0.0078125f, &Add<float>, Fixed(0.0f), Fixed(0.0078125f), &Add<Fixed>, __LINE__);
    comp(0.0f, 0.015625f, &Add<float>, Fixed(0.0f), Fixed(0.015625f), &Add<Fixed>, __LINE__);
    comp(0.0f, 0.03125f, &Add<float>, Fixed(0.0f), Fixed(0.03125f), &Add<Fixed>, __LINE__);
    comp(0.0f, 0.0625f, &Add<float>, Fixed(0.0f), Fixed(0.0625f), &Add<Fixed>, __LINE__);
    comp(0.0f, 0.125f, &Add<float>, Fixed(0.0f), Fixed(0.125f), &Add<Fixed>, __LINE__);
    comp(0.0f, 0.25f, &Add<float>, Fixed(0.0f), Fixed(0.25f), &Add<Fixed>, __LINE__);
    comp(0.0f, 0.5f, &Add<float>, Fixed(0.0f), Fixed(0.5f), &Add<Fixed>, __LINE__);
    comp(0.0f, 1.0f, &Add<float>, Fixed(0.0f), Fixed(1.0f), &Add<Fixed>, __LINE__);
    comp(8388607.0f, 0.0f, &Add<float>, Fixed(8388607.0f), Fixed(0.0f), &Add<Fixed>, __LINE__);
    comp(8388607.0f, 0.00390625f, &Add<float>, Fixed(8388607.0f), Fixed(0.00390625f), &Add<Fixed>, __LINE__);
    comp(8388607.0f, 0.0078125f, &Add<float>, Fixed(8388607.0f), Fixed(0.0078125f), &Add<Fixed>, __LINE__);
    comp(8388607.0f, 0.015625f, &Add<float>, Fixed(8388607.0f), Fixed(0.015625f), &Add<Fixed>, __LINE__);
    comp(8388607.0f, 0.03125f, &Add<float>, Fixed(8388607.0f), Fixed(0.03125f), &Add<Fixed>, __LINE__);
    comp(8388607.0f, 0.0625f, &Add<float>, Fixed(8388607.0f), Fixed(0.0625f), &Add<Fixed>, __LINE__);
    comp(8388607.0f, 0.125f, &Add<float>, Fixed(8388607.0f), Fixed(0.125f), &Add<Fixed>, __LINE__);
    comp(8388607.0f, 0.25f, &Add<float>, Fixed(8388607.0f), Fixed(0.25f), &Add<Fixed>, __LINE__);
    comp(8388607.0f, 0.5f, &Add<float>, Fixed(8388607.0f), Fixed(0.5f), &Add<Fixed>, __LINE__);
    comp(123.0f, 0.0f, &Add<float>, Fixed(123.0f), Fixed(0.0f), &Add<Fixed>, __LINE__);
    comp(123.0f, 0.00390625f, &Add<float>, Fixed(123.0f), Fixed(0.00390625f), &Add<Fixed>, __LINE__);
    comp(123.0f, 0.0078125f, &Add<float>, Fixed(123.0f), Fixed(0.0078125f), &Add<Fixed>, __LINE__);
    comp(123.0f, 0.015625f, &Add<float>, Fixed(123.0f), Fixed(0.015625f), &Add<Fixed>, __LINE__);
    comp(123.0f, 0.03125f, &Add<float>, Fixed(123.0f), Fixed(0.03125f), &Add<Fixed>, __LINE__);
    comp(123.0f, 0.0625f, &Add<float>, Fixed(123.0f), Fixed(0.0625f), &Add<Fixed>, __LINE__);
    comp(123.0f, 0.125f, &Add<float>, Fixed(123.0f), Fixed(0.125f), &Add<Fixed>, __LINE__);
    comp(123.0f, 0.25f, &Add<float>, Fixed(123.0f), Fixed(0.25f), &Add<Fixed>, __LINE__);
    comp(123.0f, 0.5f, &Add<float>, Fixed(123.0f), Fixed(0.5f), &Add<Fixed>, __LINE__);
    comp(-123.0f, 0.0f, &Add<float>, Fixed(-123.0f), Fixed(0.0f), &Add<Fixed>, __LINE__);
    comp(-123.0f, 0.00390625f, &Add<float>, Fixed(-123.0f), Fixed(0.00390625f), &Add<Fixed>, __LINE__);
    comp(-123.0f, 0.0078125f, &Add<float>, Fixed(-123.0f), Fixed(0.0078125f), &Add<Fixed>, __LINE__);
    comp(-123.0f, 0.015625f, &Add<float>, Fixed(-123.0f), Fixed(0.015625f), &Add<Fixed>, __LINE__);
    comp(-123.0f, 0.03125f, &Add<float>, Fixed(-123.0f), Fixed(0.03125f), &Add<Fixed>, __LINE__);
    comp(-123.0f, 0.0625f, &Add<float>, Fixed(-123.0f), Fixed(0.0625f), &Add<Fixed>, __LINE__);
    comp(-123.0f, 0.125f, &Add<float>, Fixed(-123.0f), Fixed(0.125f), &Add<Fixed>, __LINE__);
    comp(-123.0f, 0.25f, &Add<float>, Fixed(-123.0f), Fixed(0.25f), &Add<Fixed>, __LINE__);
    comp(-123.0f, 0.5f, &Add<float>, Fixed(-123.0f), Fixed(0.5f), &Add<Fixed>, __LINE__);

    comp(0.0f, 0.0f, &Sub<float>, Fixed(0.0f), Fixed(0.0f), &Sub<Fixed>, __LINE__);
    comp(0.00390625f, 0.0f, &Sub<float>, Fixed(0.00390625f), Fixed(0.0f), &Sub<Fixed>, __LINE__);
    comp(0.0078125f, 0.0f, &Sub<float>, Fixed(0.0078125f), Fixed(0.0f), &Sub<Fixed>, __LINE__);
    comp(0.015625f, 0.0f, &Sub<float>, Fixed(0.015625f), Fixed(0.0f), &Sub<Fixed>, __LINE__);
    comp(0.03125f, 0.0f, &Sub<float>, Fixed(0.03125f), Fixed(0.0f), &Sub<Fixed>, __LINE__);
    comp(0.0625f, 0.0f, &Sub<float>, Fixed(0.0625f), Fixed(0.0f), &Sub<Fixed>, __LINE__);
    comp(0.125f, 0.0f, &Sub<float>, Fixed(0.125f), Fixed(0.0f), &Sub<Fixed>, __LINE__);
    comp(0.25f, 0.0f, &Sub<float>, Fixed(0.25f), Fixed(0.0f), &Sub<Fixed>, __LINE__);
    comp(0.5f, 0.0f, &Sub<float>, Fixed(0.5f), Fixed(0.0f), &Sub<Fixed>, __LINE__);
    comp(1.0f, 0.0f, &Sub<float>, Fixed(1.0f), Fixed(0.0f), &Sub<Fixed>, __LINE__);
    comp(0.0f, 0.00390625f, &Sub<float>, Fixed(0.0f), Fixed(0.00390625f), &Sub<Fixed>, __LINE__);
    comp(0.0f, 0.0078125f, &Sub<float>, Fixed(0.0f), Fixed(0.0078125f), &Sub<Fixed>, __LINE__);
    comp(0.0f, 0.015625f, &Sub<float>, Fixed(0.0f), Fixed(0.015625f), &Sub<Fixed>, __LINE__);
    comp(0.0f, 0.03125f, &Sub<float>, Fixed(0.0f), Fixed(0.03125f), &Sub<Fixed>, __LINE__);
    comp(0.0f, 0.0625f, &Sub<float>, Fixed(0.0f), Fixed(0.0625f), &Sub<Fixed>, __LINE__);
    comp(0.0f, 0.125f, &Sub<float>, Fixed(0.0f), Fixed(0.125f), &Sub<Fixed>, __LINE__);
    comp(0.0f, 0.25f, &Sub<float>, Fixed(0.0f), Fixed(0.25f), &Sub<Fixed>, __LINE__);
    comp(0.0f, 0.5f, &Sub<float>, Fixed(0.0f), Fixed(0.5f), &Sub<Fixed>, __LINE__);
    comp(0.0f, 1.0f, &Sub<float>, Fixed(0.0f), Fixed(1.0f), &Sub<Fixed>, __LINE__);
    comp(8388607.0f, 0.0f, &Sub<float>, Fixed(8388607.0f), Fixed(0.0f), &Sub<Fixed>, __LINE__);
    comp(8388607.0f, 0.00390625f, &Sub<float>, Fixed(8388607.0f), Fixed(0.00390625f), &Sub<Fixed>, __LINE__);
    comp(8388607.0f, 0.0078125f, &Sub<float>, Fixed(8388607.0f), Fixed(0.0078125f), &Sub<Fixed>, __LINE__);
    comp(8388607.0f, 0.015625f, &Sub<float>, Fixed(8388607.0f), Fixed(0.015625f), &Sub<Fixed>, __LINE__);
    comp(8388607.0f, 0.03125f, &Sub<float>, Fixed(8388607.0f), Fixed(0.03125f), &Sub<Fixed>, __LINE__);
    comp(8388607.0f, 0.0625f, &Sub<float>, Fixed(8388607.0f), Fixed(0.0625f), &Sub<Fixed>, __LINE__);
    comp(8388607.0f, 0.125f, &Sub<float>, Fixed(8388607.0f), Fixed(0.125f), &Sub<Fixed>, __LINE__);
    comp(8388607.0f, 0.25f, &Sub<float>, Fixed(8388607.0f), Fixed(0.25f), &Sub<Fixed>, __LINE__);
    comp(8388607.0f, 0.5f, &Sub<float>, Fixed(8388607.0f), Fixed(0.5f), &Sub<Fixed>, __LINE__);
    comp(123.0f, 0.0f, &Sub<float>, Fixed(123.0f), Fixed(0.0f), &Sub<Fixed>, __LINE__);
    comp(123.0f, 0.00390625f, &Sub<float>, Fixed(123.0f), Fixed(0.00390625f), &Sub<Fixed>, __LINE__);
    comp(123.0f, 0.0078125f, &Sub<float>, Fixed(123.0f), Fixed(0.0078125f), &Sub<Fixed>, __LINE__);
    comp(123.0f, 0.015625f, &Sub<float>, Fixed(123.0f), Fixed(0.015625f), &Sub<Fixed>, __LINE__);
    comp(123.0f, 0.03125f, &Sub<float>, Fixed(123.0f), Fixed(0.03125f), &Sub<Fixed>, __LINE__);
    comp(123.0f, 0.0625f, &Sub<float>, Fixed(123.0f), Fixed(0.0625f), &Sub<Fixed>, __LINE__);
    comp(123.0f, 0.125f, &Sub<float>, Fixed(123.0f), Fixed(0.125f), &Sub<Fixed>, __LINE__);
    comp(123.0f, 0.25f, &Sub<float>, Fixed(123.0f), Fixed(0.25f), &Sub<Fixed>, __LINE__);
    comp(123.0f, 0.5f, &Sub<float>, Fixed(123.0f), Fixed(0.5f), &Sub<Fixed>, __LINE__);
    comp(-123.0f, 0.0f, &Sub<float>, Fixed(-123.0f), Fixed(0.0f), &Sub<Fixed>, __LINE__);
    comp(-123.0f, 0.00390625f, &Sub<float>, Fixed(-123.0f), Fixed(0.00390625f), &Sub<Fixed>, __LINE__);
    comp(-123.0f, 0.0078125f, &Sub<float>, Fixed(-123.0f), Fixed(0.0078125f), &Sub<Fixed>, __LINE__);
    comp(-123.0f, 0.015625f, &Sub<float>, Fixed(-123.0f), Fixed(0.015625f), &Sub<Fixed>, __LINE__);
    comp(-123.0f, 0.03125f, &Sub<float>, Fixed(-123.0f), Fixed(0.03125f), &Sub<Fixed>, __LINE__);
    comp(-123.0f, 0.0625f, &Sub<float>, Fixed(-123.0f), Fixed(0.0625f), &Sub<Fixed>, __LINE__);
    comp(-123.0f, 0.125f, &Sub<float>, Fixed(-123.0f), Fixed(0.125f), &Sub<Fixed>, __LINE__);
    comp(-123.0f, 0.25f, &Sub<float>, Fixed(-123.0f), Fixed(0.25f), &Sub<Fixed>, __LINE__);
    comp(-123.0f, 0.5f, &Sub<float>, Fixed(-123.0f), Fixed(0.5f), &Sub<Fixed>, __LINE__);

    comp(0.0f, 0.0f, &Mul<float>, Fixed(0.0f), Fixed(0.0f), &Mul<Fixed>, __LINE__);
    comp(0.00390625f, 0.0f, &Mul<float>, Fixed(0.00390625f), Fixed(0.0f), &Mul<Fixed>, __LINE__);
    comp(0.0078125f, 0.0f, &Mul<float>, Fixed(0.0078125f), Fixed(0.0f), &Mul<Fixed>, __LINE__);
    comp(0.015625f, 0.0f, &Mul<float>, Fixed(0.015625f), Fixed(0.0f), &Mul<Fixed>, __LINE__);
    comp(0.03125f, 0.0f, &Mul<float>, Fixed(0.03125f), Fixed(0.0f), &Mul<Fixed>, __LINE__);
    comp(0.0625f, 0.0f, &Mul<float>, Fixed(0.0625f), Fixed(0.0f), &Mul<Fixed>, __LINE__);
    comp(0.125f, 0.0f, &Mul<float>, Fixed(0.125f), Fixed(0.0f), &Mul<Fixed>, __LINE__);
    comp(0.25f, 0.0f, &Mul<float>, Fixed(0.25f), Fixed(0.0f), &Mul<Fixed>, __LINE__);
    comp(0.5f, 0.0f, &Mul<float>, Fixed(0.5f), Fixed(0.0f), &Mul<Fixed>, __LINE__);
    comp(1.0f, 0.0f, &Mul<float>, Fixed(1.0f), Fixed(0.0f), &Mul<Fixed>, __LINE__);
    comp(0.0f, 0.00390625f, &Mul<float>, Fixed(0.0f), Fixed(0.00390625f), &Mul<Fixed>, __LINE__);
    comp(0.0f, 0.0078125f, &Mul<float>, Fixed(0.0f), Fixed(0.0078125f), &Mul<Fixed>, __LINE__);
    comp(0.0f, 0.015625f, &Mul<float>, Fixed(0.0f), Fixed(0.015625f), &Mul<Fixed>, __LINE__);
    comp(0.0f, 0.03125f, &Mul<float>, Fixed(0.0f), Fixed(0.03125f), &Mul<Fixed>, __LINE__);
    comp(0.0f, 0.0625f, &Mul<float>, Fixed(0.0f), Fixed(0.0625f), &Mul<Fixed>, __LINE__);
    comp(0.0f, 0.125f, &Mul<float>, Fixed(0.0f), Fixed(0.125f), &Mul<Fixed>, __LINE__);
    comp(0.0f, 0.25f, &Mul<float>, Fixed(0.0f), Fixed(0.25f), &Mul<Fixed>, __LINE__);
    comp(0.0f, 0.5f, &Mul<float>, Fixed(0.0f), Fixed(0.5f), &Mul<Fixed>, __LINE__);
    comp(0.0f, 1.0f, &Mul<float>, Fixed(0.0f), Fixed(1.0f), &Mul<Fixed>, __LINE__);
    comp(8388607.0f, 0.0f, &Mul<float>, Fixed(8388607.0f), Fixed(0.0f), &Mul<Fixed>, __LINE__);
    comp(8388607.0f, 0.00390625f, &Mul<float>, Fixed(8388607.0f), Fixed(0.00390625f), &Mul<Fixed>, __LINE__);
    comp(8388607.0f, 0.0078125f, &Mul<float>, Fixed(8388607.0f), Fixed(0.0078125f), &Mul<Fixed>, __LINE__);
    comp(8388607.0f, 0.015625f, &Mul<float>, Fixed(8388607.0f), Fixed(0.015625f), &Mul<Fixed>, __LINE__);
    comp(8388607.0f, 0.03125f, &Mul<float>, Fixed(8388607.0f), Fixed(0.03125f), &Mul<Fixed>, __LINE__);
    comp(8388607.0f, 0.0625f, &Mul<float>, Fixed(8388607.0f), Fixed(0.0625f), &Mul<Fixed>, __LINE__);
    comp(8388607.0f, 0.125f, &Mul<float>, Fixed(8388607.0f), Fixed(0.125f), &Mul<Fixed>, __LINE__);
    comp(8388607.0f, 0.25f, &Mul<float>, Fixed(8388607.0f), Fixed(0.25f), &Mul<Fixed>, __LINE__);
    comp(8388607.0f, 0.5f, &Mul<float>, Fixed(8388607.0f), Fixed(0.5f), &Mul<Fixed>, __LINE__);
    comp(123.0f, 0.0f, &Mul<float>, Fixed(123.0f), Fixed(0.0f), &Mul<Fixed>, __LINE__);
    comp(123.0f, 0.00390625f, &Mul<float>, Fixed(123.0f), Fixed(0.00390625f), &Mul<Fixed>, __LINE__);
    comp(123.0f, 0.0078125f, &Mul<float>, Fixed(123.0f), Fixed(0.0078125f), &Mul<Fixed>, __LINE__);
    comp(123.0f, 0.015625f, &Mul<float>, Fixed(123.0f), Fixed(0.015625f), &Mul<Fixed>, __LINE__);
    comp(123.0f, 0.03125f, &Mul<float>, Fixed(123.0f), Fixed(0.03125f), &Mul<Fixed>, __LINE__);
    comp(123.0f, 0.0625f, &Mul<float>, Fixed(123.0f), Fixed(0.0625f), &Mul<Fixed>, __LINE__);
    comp(123.0f, 0.125f, &Mul<float>, Fixed(123.0f), Fixed(0.125f), &Mul<Fixed>, __LINE__);
    comp(123.0f, 0.25f, &Mul<float>, Fixed(123.0f), Fixed(0.25f), &Mul<Fixed>, __LINE__);
    comp(123.0f, 0.5f, &Mul<float>, Fixed(123.0f), Fixed(0.5f), &Mul<Fixed>, __LINE__);
    comp(-123.0f, 0.00390625f, &Mul<float>, Fixed(-123.0f), Fixed(0.00390625f), &Mul<Fixed>, __LINE__);
    comp(-123.0f, 0.0078125f, &Mul<float>, Fixed(-123.0f), Fixed(0.0078125f), &Mul<Fixed>, __LINE__);
    comp(-123.0f, 0.015625f, &Mul<float>, Fixed(-123.0f), Fixed(0.015625f), &Mul<Fixed>, __LINE__);
    comp(-123.0f, 0.03125f, &Mul<float>, Fixed(-123.0f), Fixed(0.03125f), &Mul<Fixed>, __LINE__);
    comp(-123.0f, 0.0625f, &Mul<float>, Fixed(-123.0f), Fixed(0.0625f), &Mul<Fixed>, __LINE__);
    comp(-123.0f, 0.125f, &Mul<float>, Fixed(-123.0f), Fixed(0.125f), &Mul<Fixed>, __LINE__);
    comp(-123.0f, 0.25f, &Mul<float>, Fixed(-123.0f), Fixed(0.25f), &Mul<Fixed>, __LINE__);
    comp(-123.0f, 0.5f, &Mul<float>, Fixed(-123.0f), Fixed(0.5f), &Mul<Fixed>, __LINE__);

    comp(0.0f, 0.00390625f, &Div<float>, Fixed(0.0f), Fixed(0.00390625f), &Div<Fixed>, __LINE__);
    comp(0.0f, 0.0078125f, &Div<float>, Fixed(0.0f), Fixed(0.0078125f), &Div<Fixed>, __LINE__);
    comp(0.0f, 0.015625f, &Div<float>, Fixed(0.0f), Fixed(0.015625f), &Div<Fixed>, __LINE__);
    comp(0.0f, 0.03125f, &Div<float>, Fixed(0.0f), Fixed(0.03125f), &Div<Fixed>, __LINE__);
    comp(0.0f, 0.0625f, &Div<float>, Fixed(0.0f), Fixed(0.0625f), &Div<Fixed>, __LINE__);
    comp(0.0f, 0.125f, &Div<float>, Fixed(0.0f), Fixed(0.125f), &Div<Fixed>, __LINE__);
    comp(0.0f, 0.25f, &Div<float>, Fixed(0.0f), Fixed(0.25f), &Div<Fixed>, __LINE__);
    comp(0.0f, 0.5f, &Div<float>, Fixed(0.0f), Fixed(0.5f), &Div<Fixed>, __LINE__);
    comp(0.0f, 1.0f, &Div<float>, Fixed(0.0f), Fixed(1.0f), &Div<Fixed>, __LINE__);
    comp(123.0f, 0.00390625f, &Div<float>, Fixed(123.0f), Fixed(0.00390625f), &Div<Fixed>, __LINE__);
    comp(123.0f, 0.0078125f, &Div<float>, Fixed(123.0f), Fixed(0.0078125f), &Div<Fixed>, __LINE__);
    comp(123.0f, 0.015625f, &Div<float>, Fixed(123.0f), Fixed(0.015625f), &Div<Fixed>, __LINE__);
    comp(123.0f, 0.03125f, &Div<float>, Fixed(123.0f), Fixed(0.03125f), &Div<Fixed>, __LINE__);
    comp(123.0f, 0.0625f, &Div<float>, Fixed(123.0f), Fixed(0.0625f), &Div<Fixed>, __LINE__);
    comp(123.0f, 0.125f, &Div<float>, Fixed(123.0f), Fixed(0.125f), &Div<Fixed>, __LINE__);
    comp(123.0f, 0.25f, &Div<float>, Fixed(123.0f), Fixed(0.25f), &Div<Fixed>, __LINE__);
    comp(123.0f, 0.5f, &Div<float>, Fixed(123.0f), Fixed(0.5f), &Div<Fixed>, __LINE__);
    comp(-123.0f, 0.00390625f, &Div<float>, Fixed(-123.0f), Fixed(0.00390625f), &Div<Fixed>, __LINE__);
    comp(-123.0f, 0.0078125f, &Div<float>, Fixed(-123.0f), Fixed(0.0078125f), &Div<Fixed>, __LINE__);
    comp(-123.0f, 0.015625f, &Div<float>, Fixed(-123.0f), Fixed(0.015625f), &Div<Fixed>, __LINE__);
    comp(-123.0f, 0.03125f, &Div<float>, Fixed(-123.0f), Fixed(0.03125f), &Div<Fixed>, __LINE__);
    comp(-123.0f, 0.0625f, &Div<float>, Fixed(-123.0f), Fixed(0.0625f), &Div<Fixed>, __LINE__);
    comp(-123.0f, 0.125f, &Div<float>, Fixed(-123.0f), Fixed(0.125f), &Div<Fixed>, __LINE__);
    comp(-123.0f, 0.25f, &Div<float>, Fixed(-123.0f), Fixed(0.25f), &Div<Fixed>, __LINE__);
    comp(-123.0f, 0.5f, &Div<float>, Fixed(-123.0f), Fixed(0.5f), &Div<Fixed>, __LINE__);
}

void test(std::string info, const Fixed a) {
    std::cout << std::fixed;
    std::cout << std::setw(15) << info << " : " << a << std::endl;
}

void discordTest(void) {
    std::cout << std::endl;
    test("2 / 3", Fixed(2) / Fixed(3));
    test("2 / 0", Fixed(2) / Fixed(0));
    test("3 / 2", Fixed(3) / Fixed(2));
    test("2 / 0.5", Fixed(2) / Fixed(0.5f));
    test("3 / 0.1", Fixed(3) / Fixed(0.1f));
    test("2 / 0.5", Fixed(2) / Fixed(0.5f));
    test("-1 / 2", Fixed(-1) / Fixed(2));
    test("1.1 / -0.3", Fixed(1.1f) / Fixed(-0.3f));
    test("-1 * 2", Fixed(-1) * Fixed(2));
    test("-1.5 * 2", Fixed(-1.5f) * Fixed(2));
    test("-7 * 13", Fixed(-7) * Fixed(13));
    test("7 * -13", Fixed(7) * Fixed(-13));
    test("-3 * 13", Fixed(-3) * Fixed(13));
    test("1.1 * -0.3", Fixed(1.1f) * Fixed(-0.3f));
    test("1.1 * 0.3", Fixed(1.1f) * Fixed(0.3f));
    test("1.004 * 1,004", Fixed(1.004f) * Fixed(1.004f));
    test("2.5 * 1.25", Fixed(2.5f) * Fixed(1.25f));
    test("2.5 * 0.125", Fixed(2.5f) * Fixed(1.25f));
    test("1.25 * 2.5", Fixed(1.25f) * Fixed(2.5f));
    test("0.125 * 2.5", Fixed(0.125f) * Fixed(2.5f));
    test("0.004", Fixed(0.004f));
    test("10.004 * 1", Fixed(10.004f) * Fixed(1));
    test("10.004 / 1", Fixed(10.004f) / Fixed(1));
    test("10.004 * 2", Fixed(10.004f) * Fixed(2));
    test("10.004 / 2", Fixed(10.004f) / Fixed(2));
    test("10.004 * 0.8", Fixed(10.004f) * Fixed(0.8f));
    test("10.004 * -1", Fixed(10.004f) * Fixed(-1));
    test("10.004 / -1", Fixed(10.004f) / Fixed(-1));
    test("10.004 * -1", Fixed(10.004f) * Fixed(-2));
    test("10.004 / -2", Fixed(10.004f) / Fixed(-2));
    test("10.004 * -0.8", Fixed(10.004f) * Fixed(-0.8f));
    test("-10.004 * 1", Fixed(-10.004f) * Fixed(1));
    test("-10.004 / 1", Fixed(-10.004f) / Fixed(1));
    test("-10.004 * 1", Fixed(-10.004f) * Fixed(2));
    test("-10.004 / 2", Fixed(-10.004f) / Fixed(2));
    test("-10.004 * 0.8", Fixed(-10.004f) * Fixed(0.8f));
    test("1.1 * -0.3", Fixed(1.1f) * Fixed(-0.3f));
    test("1.1 * 0.3", Fixed(1.1f) * Fixed(0.3f));
    test("1.1 * -0.3", Fixed(-0.3f) * Fixed(1.1f));
    test("1.1 + 0.3", Fixed(0.3f) + Fixed(1.1f));
    test("0.1 + 1.3", Fixed(0.1f) + Fixed(1.3f));
    test("0.1 + -1.3", Fixed(0.1f) + Fixed(-1.3f));
    test("0.1 - 1.3", Fixed(0.1f) - Fixed(1.3f));
    test("0.1 - -1.3", Fixed(0.1f) - Fixed(-1.3f));
    test("10 - 5.33", Fixed(10) - Fixed(5.33f));
    test("10 + 5.33", Fixed(10) + Fixed(5.33f));
    test("0x400001 * 1.33", Fixed(0x400001) * Fixed(1.33f));
    test("0x200001 * 2.33", Fixed(0x200001) * Fixed(2.33f));
    test("0x100001 * 4.004", Fixed(0x100001) * Fixed(4.004f));
    test("not ovf", Fixed(1 << 22) * Fixed(1.99f));
    test("ovf", Fixed(1 << 22) * Fixed(2));
}

void pdfTest(void) {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    Fixed const c(2);
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;
}

void comparisonTest(void) {
    assert(Fixed(0.0f) > Fixed(0.0f) == false);
    assert(Fixed(1.0f) > Fixed(0.0f) == true);
    assert(Fixed(0.5f) > Fixed(0.0f) == true);
    assert(Fixed(100) > Fixed(100) == false);
    assert(Fixed(101) > Fixed(100) == true);

    assert(Fixed(0.0f) < Fixed(0.0f) == false);
    assert(Fixed(0.0f) < Fixed(1.0f) == true);
    assert(Fixed(0.5f) < Fixed(0.0f) == false);
    assert(Fixed(100) < Fixed(100) == false);
    assert(Fixed(101) < Fixed(100) == false);

    assert(Fixed(0.0f) >= Fixed(0.0f) == true);
    assert(Fixed(1.0f) >= Fixed(0.0f) == true);
    assert(Fixed(0.5f) >= Fixed(0.0f) == true);
    assert(Fixed(100) >= Fixed(100) == true);
    assert(Fixed(100) >= Fixed(101) == false);

    assert(Fixed(0.0f) <= Fixed(0.0f) == true);
    assert(Fixed(0.0f) <= Fixed(1.0f) == true);
    assert(Fixed(0.5f) <= Fixed(0.0f) == false);
    assert(Fixed(100) <= Fixed(100) == true);
    assert(Fixed(101) <= Fixed(100) == false);

    assert(Fixed(0.0f) == Fixed(0.0f) == true);
    assert(Fixed(0.0f) == Fixed(1.0f) == false);
    assert(Fixed(0.5f) == Fixed(0.0f) == false);
    assert(Fixed(100) == Fixed(100) == true);
    assert(Fixed(101) == Fixed(100) == false);

    assert(Fixed(0.0f) != Fixed(0.0f) == false);
    assert(Fixed(0.0f) != Fixed(1.0f) == true);
    assert(Fixed(0.5f) != Fixed(0.0f) == true);
    assert(Fixed(100) != Fixed(100) == false);
    assert(Fixed(101) != Fixed(100) == true);
}

int main(void) {
    pdfTest();
    originalTest();
    discordTest();
    comparisonTest();

    return 0;
}
