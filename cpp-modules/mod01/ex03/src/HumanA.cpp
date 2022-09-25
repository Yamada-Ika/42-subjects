#include "HumanA.hpp"

#include <iostream>

HumanA::HumanA(std::string name, const Weapon &weapon) : name_(name), weapon_(weapon) {}

HumanA::~HumanA(void) {}

void HumanA::attack(void) const {
    std::cout << name_ + " attacks with their " + weapon_.getType() << std::endl;
}
