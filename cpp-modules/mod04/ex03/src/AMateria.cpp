#include "AMateria.hpp"

#include <string>
#include <iostream>

AMateria::AMateria(void) {}

AMateria::AMateria(std::string const & type_name) : type(type_name) {
    // type = type_name;
}

AMateria::AMateria(const AMateria& other) {
    *this = other;
}

AMateria::~AMateria(void) {}

AMateria& AMateria::operator=(const AMateria &other) {
    this->type = other.type;
    return *this;
}

std::string const & AMateria::getType(void) const {
    return type;
}

void AMateria::setType(std::string const& type_name) {
    type = type_name;
}

void AMateria::use(ICharacter& target) {
    std::cout << "* use materia for " << target.getName() << " *" << std::endl;
}

