#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include <string>

class DiamondTrap : public FragTrap, public ScavTrap {
 private:
    std::string Name_;

 public:
    DiamondTrap(void);
    explicit DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap& other);
    ~DiamondTrap(void);
    DiamondTrap& operator=(const DiamondTrap& other);
    virtual void attack(std::string const &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    // virtual void takeDamage(unsigned int amount);
    // virtual void beRepaired(unsigned int amount);
    void whoAmI(void);
};

#endif
