#ifndef DOG_HPP
# define DOG_HPP

# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
 private:
    Brain*  brain_;

 public:
    Dog(void);
    Dog(const Dog& other);
    ~Dog(void);
    Dog& operator=(const Dog& other);
    virtual void  makeSound(void) const;
};

#endif
