#include "Cat.hpp"

#include <iostream>

Cat::Cat(void) : brain_(new Brain()) {
    std::cout << "Cat default constructor called" << std::endl;
    type = "Cat";
}

Cat::Cat(const Cat& other) : brain_(NULL) {
    std::cout << "Cat copy constructor called" << std::endl;
    *this = other;
}

Cat::~Cat(void) {
    std::cout << "Cat destructor called" << std::endl;
    delete brain_;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assignation operator called" << std::endl;

    if (this == &other) return *this;

    this->type = other.type;
    delete this->brain_;
    this->brain_ = new Brain();
    *this->brain_ = *other.brain_;
    return *this;
}

void  Cat::makeSound(void) const {
    std::cout << "meow meow" << std::endl;
}
