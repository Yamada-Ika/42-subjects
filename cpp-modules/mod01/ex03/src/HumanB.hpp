#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB {
 private:
    std::string name_;
    Weapon *weapon_;

 public:
    explicit HumanB(std::string name);
    ~HumanB(void);
    void attack(void) const;
    void setWeapon(const Weapon &weapon);
};

#endif
