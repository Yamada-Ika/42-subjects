#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {
 private:
    std::string first_name_;
    std::string last_name_;
    std::string nickname_;
    std::string phone_number_;
    std::string darkest_secret_;

 public:
    Contact(void);
    void setFirstName(std::string first_name);
    void setLastName(std::string last_name);
    void setNickName(std::string nickname);
    void setPhoneNumber(std::string phone_number);
    void setDarkestSecret(std::string darkest_secret);
    std::string getFirstName(void);
    std::string getLastName(void);
    std::string getNickName(void);
    std::string getPhoneNumber(void);
    std::string getDarkestSecret(void);
};

#endif
