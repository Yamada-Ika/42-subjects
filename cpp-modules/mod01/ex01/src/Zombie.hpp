#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
 private:
    std::string name_;

 public:
    explicit Zombie(std::string name);
    Zombie();
    ~Zombie();
    void announce(void);
    void setName(const std::string &name);
};

#endif
