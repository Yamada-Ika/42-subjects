#include "WrongAnimal.hpp"

#include <iostream>

WrongAnimal::WrongAnimal(void) : type("") {
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type) {
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = other;
}

WrongAnimal::~WrongAnimal(void) {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << "WrongAnimal assignation operator called" << std::endl;
    this->type = other.type;
    return *this;
}

std::string  WrongAnimal::getType(void) const {
    return type;
}

void  WrongAnimal::makeSound(void) const {
    std::cout << "WrongAnimal makeSound called" << std::endl;
}
