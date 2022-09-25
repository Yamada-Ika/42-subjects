#include "Dog.hpp"

#include <iostream>

Dog::Dog(void) {
    std::cout << "Dog default constructor called" << std::endl;
    type = "Dog";
}

Dog::Dog(const Dog& other) {
    std::cout << "Dog copy constructor called" << std::endl;
    *this = other;
}

Dog::~Dog(void) {
    std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assignation operator called" << std::endl;
    this->type = other.type;
    return *this;
}

void  Dog::makeSound(void) const {
    std::cout << "woof woof" << std::endl;
}
