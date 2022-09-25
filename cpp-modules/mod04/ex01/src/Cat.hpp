#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
 private:
    Brain*  brain_;

 public:
    Cat(void);
    Cat(const Cat& other);
    ~Cat(void);
    Cat& operator=(const Cat& other);
    virtual void  makeSound(void) const;
};

#endif
