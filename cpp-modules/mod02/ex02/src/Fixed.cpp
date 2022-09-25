#include "Fixed.hpp"

#include <iostream>
#include <cmath>

Fixed::Fixed(void) : rawbits_(0) {}

Fixed::Fixed(int integer) {
    rawbits_ = integer << fractbitswidth_;
}

Fixed::Fixed(float floater) {
    rawbits_ = static_cast<int>(roundf(floater * (1 << fractbitswidth_)));
}

Fixed::Fixed(const Fixed& other) {
    *this = other;
}

Fixed::~Fixed(void) {}

Fixed& Fixed::operator=(const Fixed& other) {
    this->rawbits_ = other.rawbits_;
    return *this;
}

int Fixed::getRawBits(void) const {
    return rawbits_;
}

void Fixed::setRawBits(int const raw) {
    rawbits_ = raw;
}

int Fixed::toInt(void) const {
    return rawbits_ >> fractbitswidth_;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(rawbits_) / (1 << fractbitswidth_);
}

std::ostream& operator<<(std::ostream& lhs, const Fixed& rhs) {
    lhs << rhs.toFloat();
    return lhs;
}

Fixed Fixed::operator+ (const Fixed& rhs) const {
    Fixed add;

    add.setRawBits(rawbits_ + rhs.getRawBits());
    return add;
}

Fixed Fixed::operator- (const Fixed& rhs) const {
    Fixed sub;

    sub.setRawBits(rawbits_ - rhs.getRawBits());
    return sub;
}

Fixed Fixed::operator* (const Fixed& rhs) const {
    Fixed mul;

    long lhs_raw = this->getRawBits();
    long rhs_raw = rhs.getRawBits();

    mul.setRawBits((lhs_raw * rhs_raw) / (1 << fractbitswidth_));
    return mul;
}

Fixed Fixed::operator/ (const Fixed& rhs) const {
    Fixed div;

    long lhs_raw = this->getRawBits();
    long rhs_raw = rhs.getRawBits();

    div.setRawBits(lhs_raw * (1 << fractbitswidth_) / rhs_raw);
    return div;
}

bool Fixed::operator< (const Fixed& rhs) const {
    return rawbits_ < rhs.getRawBits();
}

bool Fixed::operator<= (const Fixed& rhs) const {
    return rawbits_ <= rhs.getRawBits();
}

bool Fixed::operator> (const Fixed& rhs) const {
    return rawbits_ > rhs.getRawBits();
}

bool Fixed::operator>= (const Fixed& rhs) const {
    return rawbits_ >= rhs.getRawBits();
}

bool Fixed::operator== (const Fixed& rhs) const {
    return rawbits_ == rhs.getRawBits();
}

bool Fixed::operator!= (const Fixed& rhs) const {
    return rawbits_ != rhs.getRawBits();
}

Fixed& Fixed::operator++() {
    rawbits_++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed prev = *this;

    rawbits_++;
    return prev;
}

Fixed& Fixed::operator--() {
    rawbits_--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed prev = *this;

    rawbits_--;
    return prev;
}

Fixed& Fixed::max(Fixed& lhs, Fixed& rhs) {
    if (lhs < rhs) {
        return rhs;
    }
    return lhs;
}

Fixed& Fixed::max(const Fixed& lhs, const Fixed& rhs) {
    if (lhs < rhs) {
        return const_cast<Fixed &>(rhs);
    }
    return const_cast<Fixed &>(lhs);
}

Fixed& Fixed::min(Fixed& lhs, Fixed& rhs) {
    if (lhs > rhs) {
        return rhs;
    }
    return lhs;
}

Fixed& Fixed::min(const Fixed& lhs, const Fixed& rhs) {
    if (lhs > rhs) {
        return const_cast<Fixed &>(rhs);
    }
    return const_cast<Fixed &>(lhs);
}
