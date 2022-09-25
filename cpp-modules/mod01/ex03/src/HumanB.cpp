#include "HumanB.hpp"

#include <iostream>

HumanB::HumanB(std::string name) : name_(name), weapon_(NULL) {}

HumanB::~HumanB(void) {}

void HumanB::attack(void) const {
    if (weapon_ == NULL) {
        std::cout << name_ + " can not attack" << std::endl;
        return;
    }
    std::cout << name_ + " attacks with their " + weapon_->getType() << std::endl;
}

void HumanB::setWeapon(const Weapon &weapon) {
    weapon_ = const_cast<Weapon *>(&weapon);
}
