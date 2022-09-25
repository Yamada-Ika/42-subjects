#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include <string>
#include <exception>

class ShrubberyCreationForm : public Form {
 private:
    static const int kGradeToSign = 145;
    static const int kGradeToExec = 137;
    std::string target_;

 public:
    ShrubberyCreationForm();
    explicit ShrubberyCreationForm(std::string& target);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

    virtual void execute(Bureaucrat const & executor) const;
    const std::string &getTarget() const;
};

std::ostream& operator<<(std::ostream& lhs, const ShrubberyCreationForm& rhs);

#endif
