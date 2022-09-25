#include "Dog.hpp"

#include <iostream>

Dog::Dog(void) : brain_(new Brain()) {
    std::cout << "Dog default constructor called" << std::endl;
    type = "Dog";
}

Dog::Dog(const Dog& other) : brain_(NULL) {
    std::cout << "Dog copy constructor called" << std::endl;
    *this = other;
}

Dog::~Dog(void) {
    std::cout << "Dog destructor called" << std::endl;
    delete brain_;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assignation operator called" << std::endl;

    if (this == &other) return *this;

    this->type = other.type;
    delete this->brain_;
    this->brain_ = new Brain();
    *this->brain_ = *other.brain_;
    return *this;
}

void  Dog::makeSound(void) const {
    std::cout << "woof woof" << std::endl;
}
