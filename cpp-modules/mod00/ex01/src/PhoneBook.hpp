#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>

# include "Contact.hpp"

# define MAX_SIZE 8

class PhoneBook {
 private:
    Contact contacts_[MAX_SIZE];
    size_t curIdx_;

 public:
    PhoneBook(void);
    void Add(Contact &info);
    void Search(void);
    void Exit(void);
};

#endif
