#include "WrongCat.hpp"

#include <iostream>

WrongCat::WrongCat(void) {
    std::cout << "WrongCat default constructor called" << std::endl;
    type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other) {
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = other;
}

WrongCat::~WrongCat(void) {
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << "WrongCat assignation operator called" << std::endl;
    this->type = other.type;
    return *this;
}

void  WrongCat::makeSound(void) const {
    std::cout << "meow meow" << std::endl;
}
