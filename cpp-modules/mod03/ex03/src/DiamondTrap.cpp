#include "DiamondTrap.hpp"

#include <iostream>

DiamondTrap::DiamondTrap(void) : Name_("") {
    std::cout << "DiamondTrap default constructor called" << std::endl;
    ClapTrap::Name_ = "_clap_name";
    Hitpoints_ = FragTrap::kDefaultHitpoints;
    Energy_points_  = ScavTrap::kDefaultEnergy_points;
    Attack_damage_ = FragTrap::kDefaultAttack_damage;
}

DiamondTrap::DiamondTrap(std::string name) : Name_(name) {
    std::cout << "DiamondTrap default constructor called" << std::endl;
    ClapTrap::Name_ = name + "_clap_name";
    Hitpoints_ = FragTrap::kDefaultHitpoints;
    Energy_points_  = ScavTrap::kDefaultEnergy_points;
    Attack_damage_ = FragTrap::kDefaultAttack_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) {
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    *this = other;
}

DiamondTrap::~DiamondTrap(void) {
    std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    std::cout << "DiamondTrap assignation operator called" << std::endl;
    this->Name_ = other.Name_;
    this->ClapTrap::Name_ = other.ClapTrap::Name_;
    this->Hitpoints_ = other.Hitpoints_;
    this->Energy_points_ = other.Energy_points_;
    this->Attack_damage_ = other.Attack_damage_;
    return *this;
}

void DiamondTrap::attack(std::string const &target) {
    ScavTrap::attack(target);
}

void DiamondTrap::takeDamage(unsigned int amount) {
    if (Hitpoints_ < amount) {
        Hitpoints_ = 0;
    } else {
        Hitpoints_ -= amount;
    }
    std::cout << "DiamondTrap " + Name_ + " take " << amount << " points of damage!" << std::endl;
}

void DiamondTrap::beRepaired(unsigned int amount) {
    if (isEnergyEmpty() || isDead()) {
        std::cout << "DiamondTrap " + Name_ + " cannot do anything!" << std::endl;
        return;
    }
    Energy_points_--;
    if (Hitpoints_ > UINT_MAX - amount) {
        Hitpoints_ = UINT_MAX;
    } else {
        Hitpoints_ += amount;
    }
    std::cout << "DiamondTrap " + Name_ + " repaired " << amount << " hitpoints!" << std::endl;
}

void DiamondTrap::whoAmI(void) {
    std::cout << "DiamondTrap : name_ [" + Name_ << "] ClapTrap::name [" << ClapTrap::Name_ << "]" << std::endl;
}

