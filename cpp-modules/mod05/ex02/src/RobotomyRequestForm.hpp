#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include <string>
#include <exception>

class RobotomyRequestForm : public Form {
 private:
    static const int kGradeToSign = 72;
    static const int kGradeToExec = 45;
    std::string target_;

 public:
    RobotomyRequestForm();
    explicit RobotomyRequestForm(std::string& target);
    ~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

    virtual void execute(Bureaucrat const & executor) const;
    const std::string &getTarget() const;
};

std::ostream& operator<<(std::ostream& lhs, const RobotomyRequestForm& rhs);

#endif
