#include "Fixed.hpp"

#include <iostream>
#include <cmath>

Fixed::Fixed(void) : rawbits_(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int integer) : rawbits_(integer << fractbitswidth_) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float floater) {
    std::cout << "Float constructor called" << std::endl;
    rawbits_ = static_cast<int>(roundf(floater * (1 << fractbitswidth_)));
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->rawbits_ = other.rawbits_;
    return *this;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return rawbits_;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
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
