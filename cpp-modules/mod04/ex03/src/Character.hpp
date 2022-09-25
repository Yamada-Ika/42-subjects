#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>

class AMateria;

class Character : public ICharacter {
 private:
    static const int kMaxSize = 4;
    AMateria *slot[kMaxSize];
    std::string name_;
    void initSlot();

 public:
    Character();
    Character(std::string const &name);
    Character(Character const &other);
    ~Character();
    Character& operator=(const Character& other);

    virtual std::string const & getName() const;
    virtual void equip(AMateria *m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);
};

#endif
