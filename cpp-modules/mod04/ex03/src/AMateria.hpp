#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
#include "Character.hpp"
#include "ICharacter.hpp"

class ICharacter;

class AMateria {
 protected:
    std::string type;

 public:
    AMateria();
    AMateria(std::string const & type_name);
    AMateria(const AMateria& other);
    virtual ~AMateria();
    AMateria& operator=(const AMateria& other);

    std::string const & getType(void) const;
    void setType(std::string const& type_name);

    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif
