#include "FragTrap.hpp"

#include <iostream>

FragTrap::FragTrap(void) {
    std::cout << "FragTrap default constructor called" << std::endl;
    Name_ = "";
    Hitpoints_ = 100;
    Energy_points_ = 100;
    Attack_damage_ = 30;
}

FragTrap::FragTrap(std::string name) {
    std::cout << "FragTrap default constructor called" << std::endl;
    Name_ = name;
    Hitpoints_ = 100;
    Energy_points_ = 100;
    Attack_damage_ = 30;
}

FragTrap::FragTrap(const FragTrap& other) {
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = other;
}

FragTrap::~FragTrap(void) {
    std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << "FragTrap assignation operator called" << std::endl;
    this->Name_ = other.Name_;
    this->Hitpoints_ = other.Hitpoints_;
    this->Energy_points_ = other.Energy_points_;
    this->Attack_damage_ = other.Attack_damage_;
    return *this;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap request a positive high fives" << std::endl;
}
