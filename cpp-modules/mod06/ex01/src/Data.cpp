#include "Data.hpp"

#include <iostream>

Data::Data() : hoge1(123), hoge2("hoge2"), hoge3(987.654) {}

Data::~Data() {}

Data::Data(const Data& other) {
    *this = other;
}

Data& Data::operator=(const Data& other) {
    if (this == &other) return *this;

    this->hoge1 = other.hoge1;
    this->hoge2 = other.hoge2;
    this->hoge3 = other.hoge3;
    return *this;
}

void Data::setHoge1(int v) { hoge1 = v; }
void Data::setHoge2(const std::string& v) { hoge2 = v; }
void Data::setHoge3(double v) { hoge3 = v; }
int Data::getHoge1() const { return hoge1; }
const std::string& Data::getHoge2() const { return hoge2; }
double Data::getHoge3() const { return hoge3; }

std::ostream& operator<<(std::ostream& lhs, const Data& rhs) {
    lhs << "Data ";
    lhs << "hoge1 : " << rhs.getHoge1() << " ";
    lhs << "hoge2 : " << rhs.getHoge2() << " ";
    lhs << "hoge3 : " << rhs.getHoge3() << " ";
    return lhs;
}

