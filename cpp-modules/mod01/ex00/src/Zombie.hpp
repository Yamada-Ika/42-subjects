#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie {
 private:
    std::string name_;

 public:
    explicit Zombie(std::string name);
    Zombie();
    ~Zombie();
    void announce(void);
};

#endif
