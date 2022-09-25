#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap(void) {
    std::cout << "ScavTrap default constructor called" << std::endl;
    Name_ = "";
    Hitpoints_ = 100;
    Energy_points_ = 50;
    Attack_damage_ = 20;
}

ScavTrap::ScavTrap(std::string name) {
    std::cout << "ScavTrap default constructor called" << std::endl;
    Name_ = name;
    Hitpoints_ = 100;
    Energy_points_ = 50;
    Attack_damage_ = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) {
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = other;
}

ScavTrap::~ScavTrap(void) {
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "ScavTrap assignation operator called" << std::endl;
    this->Name_ = other.Name_;
    this->Hitpoints_ = other.Hitpoints_;
    this->Energy_points_ = other.Energy_points_;
    this->Attack_damage_ = other.Attack_damage_;
    return *this;
}

void ScavTrap::attack(std::string const &target) {
    if (isEnergyEmpty() || isDead()) {
        std::cout << "ScavTrap " + this->Name_ + " cannot do anything!" << std::endl;
        return;
    }
    Energy_points_--;
    std::cout << "ScavTrap " + this->Name_ + " attack " + target + ", causing ";
    std::cout << this->Attack_damage_ << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(void) {
    std::cout << "ScavTrap enterred in Gate keeper mode." << std::endl;
}
