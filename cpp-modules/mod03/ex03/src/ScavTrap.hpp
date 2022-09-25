#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <string>

class ScavTrap : virtual public ClapTrap {
 protected:
    static const unsigned int kDefaultHitpoints = 100;
    static const unsigned int kDefaultEnergy_points = 50;
    static const unsigned int kDefaultAttack_damage = 20;

 public:
    ScavTrap(void);
    explicit ScavTrap(std::string name);
    ScavTrap(const ScavTrap& other);
    ~ScavTrap(void);
    ScavTrap& operator=(const ScavTrap& other);
    virtual void attack(std::string const &target);
    void guardGate(void);
};

#endif
