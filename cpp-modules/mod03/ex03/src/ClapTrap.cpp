#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap(void) : Name_(""),
                            Hitpoints_(10),
                            Energy_points_(10),
                            Attack_damage_(0) {
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : Name_(name),
                                        Hitpoints_(10),
                                        Energy_points_(10),
                                        Attack_damage_(0) {
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = other;
}

ClapTrap::~ClapTrap(void) {
    std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "ClapTrap assignation operator called" << std::endl;
    this->Name_ = other.Name_;
    this->Hitpoints_ = other.Hitpoints_;
    this->Energy_points_ = other.Energy_points_;
    this->Attack_damage_ = other.Attack_damage_;
    return *this;
}

void ClapTrap::attack(const std::string &target) {
    if (isEnergyEmpty() || isDead()) {
        std::cout << "ClapTrap " + this->Name_ + " cannot do anything!" << std::endl;
        return;
    }
    Energy_points_--;
    std::cout << "ClapTrap " + this->Name_ + " attack " + target + ", causing ";
    std::cout << this->Attack_damage_ << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (Hitpoints_ < amount) {
        Hitpoints_ = 0;
    } else {
        Hitpoints_ -= amount;
    }
    std::cout << "ClapTrap " + this->Name_ + " take " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (isEnergyEmpty() || isDead()) {
        std::cout << "ClapTrap " + this->Name_ + " cannot do anything!" << std::endl;
        return;
    }
    Energy_points_--;
    if (Hitpoints_ > UINT_MAX - amount) {
        Hitpoints_ = UINT_MAX;
    } else {
        Hitpoints_ += amount;
    }
    std::cout << "ClapTrap " + this->Name_ + " repaired " << amount << " hitpoints!" << std::endl;
}

bool ClapTrap::isDead(void) {
    return Hitpoints_ == 0;
}

bool ClapTrap::isEnergyEmpty(void) {
    return Energy_points_ == 0;
}
