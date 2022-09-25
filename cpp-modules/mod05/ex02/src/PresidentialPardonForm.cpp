#include "PresidentialPardonForm.hpp"
#include "Form.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() :
        Form("PresidentialPardonForm", kGradeToSign, kGradeToExec), target_("none") {
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string& target) :
        Form("PresidentialPardonForm", kGradeToSign, kGradeToExec), target_(target) {
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    std::cout << "PresidentialPardonForm assignation operator called" << std::endl;
    this->target_ = other.target_;
    return *this;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
        Form("PresidentialPardonForm", kGradeToSign, kGradeToExec),
        target_(other.target_) {
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
    *this = other;
}

const std::string &PresidentialPardonForm::getTarget(void) const {
    return target_;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (!getIsSigned()) {
        throw Form::NotSignedException();
    }
    if (!canExec(executor)) {
        throw Form::CannotExecException();
    }
    std::cout << target_ + " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::ostream& operator<<(std::ostream& lhs, const PresidentialPardonForm& rhs) {
    lhs << "Target : ";
    lhs << rhs.getTarget();
    lhs << ", ";
    lhs << "Name : ";
    lhs << rhs.getName();
    lhs << ", ";
    lhs << "Grade to sign : ";
    lhs << rhs.getGradeToSign();
    lhs << ", ";
    lhs << "Grade to execute : ";
    lhs << rhs.getGradeToExec();
    lhs << ", ";
    return lhs;
}
