#ifndef CURE_HPP
# define CURE_HPP

#include <string>
#include "AMateria.hpp"

class Cure : public AMateria {
 public:
    Cure();
    Cure(const Cure& other);
    ~Cure();
    Cure& operator=(const Cure& other);

    virtual AMateria* clone(void) const;
    virtual void use(ICharacter& target);
};

#endif
