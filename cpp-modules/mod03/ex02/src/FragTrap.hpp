#ifndef FragTrap_HPP
# define FragTrap_HPP

# include "ClapTrap.hpp"
# include <string>

class FragTrap : public ClapTrap {
 public:
    FragTrap(void);
    explicit FragTrap(std::string name);
    FragTrap(const FragTrap& other);
    ~FragTrap(void);
    FragTrap& operator=(const FragTrap& other);
    void highFivesGuys(void);
};

#endif
