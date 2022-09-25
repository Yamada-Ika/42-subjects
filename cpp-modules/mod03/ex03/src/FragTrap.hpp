#ifndef FragTrap_HPP
# define FragTrap_HPP

# include "ClapTrap.hpp"
# include <string>

class FragTrap : virtual public ClapTrap {
 protected:
    static const unsigned int kDefaultHitpoints = 100;
    static const unsigned int kDefaultEnergy_points = 100;
    static const unsigned int kDefaultAttack_damage = 30;

 public:
    FragTrap(void);
    explicit FragTrap(std::string name);
    FragTrap(const FragTrap& other);
    ~FragTrap(void);
    FragTrap& operator=(const FragTrap& other);
    void highFivesGuys(void);
};

#endif
