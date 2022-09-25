#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon {
 private:
    std::string type_;

 public:
    explicit Weapon(std::string type);
    Weapon(void);
    ~Weapon(void);
    const std::string &getType(void) const;
    void setType(std::string type);
};

#endif
