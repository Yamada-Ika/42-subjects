#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"
#include <string>
#include <exception>

class PresidentialPardonForm : public Form {
 private:
    static const int kGradeToSign = 25;
    static const int kGradeToExec = 5;
    std::string target_;

 public:
    PresidentialPardonForm();
    explicit PresidentialPardonForm(std::string& target);
    ~PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

    virtual void execute(Bureaucrat const & executor) const;
    const std::string &getTarget(void) const;
};

std::ostream& operator<<(std::ostream& lhs, const PresidentialPardonForm& rhs);

#endif
