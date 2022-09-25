#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <cassert>

void internTest1(void) {
    std::cout << "--- " << __func__ << " start! ---" << std::endl;
    std::cout << std::endl;

    Form* rrf;

    try {
        Intern someRandomIntern;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        Bureaucrat b("someone", 40);
        std::cout << b << std::endl;
        std::cout << *rrf << std::endl;
        b.signForm(*rrf);
        b.executeForm(*rrf);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    delete rrf;

    std::cout << std::endl;
    std::cout << "--- " << __func__ << " end! ---" << std::endl;
}

void internTest2(void) {
    std::cout << "--- " << __func__ << " start! ---" << std::endl;
    std::cout << std::endl;

    Form* rrf;

    try {
        Intern someRandomIntern;
        rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
        Bureaucrat b("someone", 40);
        std::cout << b << std::endl;
        std::cout << *rrf << std::endl;
        b.executeForm(*rrf);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    delete rrf;

    std::cout << std::endl;
    std::cout << "--- " << __func__ << " end! ---" << std::endl;
}

void internTest3(void) {
    std::cout << "--- " << __func__ << " start! ---" << std::endl;
    std::cout << std::endl;

    Form* rrf;

    try {
        Intern someRandomIntern;
        rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
        Bureaucrat b("someone", 46);
        std::cout << b << std::endl;
        std::cout << *rrf << std::endl;
        b.signForm(*rrf);
        b.executeForm(*rrf);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    delete rrf;

    std::cout << std::endl;
    std::cout << "--- " << __func__ << " end! ---" << std::endl;
}

void internTest4(void) {
    std::cout << "--- " << __func__ << " start! ---" << std::endl;
    std::cout << std::endl;

    Form* rrf;

    try {
        Intern someRandomIntern;
        rrf = someRandomIntern.makeForm("nosuch form", "Bender");
        assert(rrf == NULL);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    delete rrf;

    std::cout << std::endl;
    std::cout << "--- " << __func__ << " end! ---" << std::endl;
}

int main() {
    internTest1();
    internTest2();
    internTest3();
    internTest4();
    return 0;
}
