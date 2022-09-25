#include "Ice.hpp"

#include <iostream>

Ice::Ice() {
    // std::cout << "Ice default constructor called" << std::endl;
    type = "ice";
}

Ice::Ice(const Ice& other) {
    *this = other;
}

Ice::~Ice() {
    // std::cout << "Ice destructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& other) {
    this->type = other.type;
    return *this;
}

AMateria* Ice::clone(void) const {
    return new Ice();
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
