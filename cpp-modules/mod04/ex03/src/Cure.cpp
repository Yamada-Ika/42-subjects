#include "Cure.hpp"

#include <iostream>

Cure::Cure() {
    //   std::cout << "Cure default constructor called" << std::endl;
    type = "cure";
}

Cure::Cure(const Cure& other) {
    *this = other;
}

Cure::~Cure() {
    // std::cout << "Cure destructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& other) {
    this->type = other.type;
    return *this;
}

AMateria* Cure::clone(void) const {
    return new Cure();
}

void Cure::use(ICharacter& target) {
  std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
