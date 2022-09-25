#include <string>
#include "Form.hpp"

class Intern {
 private:
    static const int kNumOfForms = 3;

    Form *newShrubberyForm(const std::string& target);
    Form *newPresidentialForm(const std::string& target);
    Form *newRobotomyForm(const std::string& target);

 public:
    Intern();
    ~Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);

    Form *makeForm(const std::string& form_name, const std::string& target);
};
