#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

Intern::Intern() {
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::~Intern() {
    std::cout << "Intern destructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& other) {
    std::cout << "Intern assignation operator called" << std::endl;
    (Intern)other;
    return *this;
}

Intern::Intern(const Intern& other) {
    std::cout << "Intern copy constructor called" << std::endl;
    *this = other;
}

Form *Intern::newShrubberyForm(const std::string& target) {
    return new ShrubberyCreationForm(const_cast<std::string&>(target));
}

Form *Intern::newPresidentialForm(const std::string& target) {
    return new PresidentialPardonForm(const_cast<std::string&>(target));
}

Form *Intern::newRobotomyForm(const std::string& target) {
    return new RobotomyRequestForm(const_cast<std::string&>(target));
}

Form *Intern::makeForm(const std::string& form_name, const std::string& target) {
    std::string form_names[kNumOfForms] = {
        "shrubbery creation",
        "presidential pardon",
        "robotomy request"
        };
    Form* (Intern::*forms[kNumOfForms])(const std::string&) = {
            &Intern::newShrubberyForm,
            &Intern::newPresidentialForm,
            &Intern::newRobotomyForm,
        };

    for (int i = 0; i < kNumOfForms; i++) {
        if (form_name == form_names[i]) {
            std::cout << "Intern creates " + form_name << std::endl;
            return (this->*forms[i])(target);
        }
    }
    std::cout << "Error: Intern does not know " + form_name << std::endl;
    return NULL;
}
