#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type_(type) {}

Weapon::Weapon(void) : type_("") {}

Weapon::~Weapon(void) {}

const std::string& Weapon::getType(void) const {
    return type_;
}

void Weapon::setType(std::string type) {
    type_ = type;
}
