#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() :
        Form("ShrubberyCreationForm", kGradeToSign, kGradeToExec),
        target_("none") {
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string &target) :
        Form("ShrubberyCreationForm", kGradeToSign, kGradeToExec),
        target_(target) {
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    std::cout << "ShrubberyCreationForm assignation operator called" << std::endl;

    if (this == &other) return *this;

    this->target_ = other.target_;
    return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
        Form("ShrubberyCreationForm", kGradeToSign, kGradeToExec),
        target_(other.target_) {
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
    *this = other;
}

const std::string &ShrubberyCreationForm::getTarget(void) const {
    return target_;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    std::string name = target_ + "_shrubbery";
    std::string content;

    if (!getIsSigned()) {
        throw Form::NotSignedException();
    }
    if (!canExec(executor)) {
        throw Form::CannotExecException();
    }

    std::ofstream ofs(name);
    if (!ofs) {
        throw std::runtime_error("error: Failed to open file.");
    }
    content =  "           \n";
    content += "     *     \n";
    content += "    ***    \n";
    content += "    ***    \n";
    content += "  *******  \n";
    content += " ********* \n";
    content += "    ***    \n";
    content += "    ***    \n";
    content += "▇▇▇▇▇▇▇▇▇▇▇\n";
    ofs << content << std::endl;
}

std::ostream& operator<<(std::ostream& lhs, const ShrubberyCreationForm& rhs) {
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
