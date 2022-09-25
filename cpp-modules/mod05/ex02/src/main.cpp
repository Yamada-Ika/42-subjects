#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

// ex00

void ex00gradeTooHighTest(void) {
    std::cout << "--- " << __func__ << " start! ---" << std::endl;
    std::cout << std::endl;

    try {
        Bureaucrat a("hoge", -1);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "--- " << __func__ << " end! ---" << std::endl;
}

void ex00gradeTooLowTest(void) {
    std::cout << "--- " << __func__ << " start! ---" << std::endl;
    std::cout << std::endl;

    try {
        Bureaucrat a("hoge", 151);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "--- " << __func__ << " end! ---" << std::endl;
}

void ex00increGradeTest(void) {
    std::cout << "--- " << __func__ << " start! ---" << std::endl;
    std::cout << std::endl;

    try {
        Bureaucrat a("hoge", 2);
        std::cout << a << std::endl;
        a.increGrade();
        std::cout << a << std::endl;
        a.increGrade();
        std::cout << a << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "--- " << __func__ << " end! ---" << std::endl;
}

void ex00decreGradeTest(void) {
    std::cout << "--- " << __func__ << " start! ---" << std::endl;
    std::cout << std::endl;

    try {
        Bureaucrat a("hoge", 149);
        std::cout << a << std::endl;
        a.decreGrade();
        std::cout << a << std::endl;
        a.decreGrade();
        std::cout << a << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "--- " << __func__ << " end! ---" << std::endl;
}

void ex00Test() {
    ex00gradeTooHighTest();
    ex00gradeTooLowTest();
    ex00increGradeTest();
    ex00decreGradeTest();
}

void ShrubberyCreationFormNormalTest(void) {
    std::cout << "--- " << __func__ << " start! ---" << std::endl;
    std::cout << std::endl;

    try {
        ShrubberyCreationForm s;
        Bureaucrat a("hoge", 3);
        std::cout << s << std::endl;
        std::cout << a << std::endl;
        a.signForm(s);
        a.executeForm(s);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "--- " << __func__ << " end! ---" << std::endl;
}

void ShrubberyCreationFormNotSignedTest(void) {
    std::cout << "--- " << __func__ << " start! ---" << std::endl;
    std::cout << std::endl;

    try {
        ShrubberyCreationForm s;
        Bureaucrat a("hoge", 3);
        std::cout << s << std::endl;
        std::cout << a << std::endl;
        a.executeForm(s);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "--- " << __func__ << " end! ---" << std::endl;
}

void ShrubberyCreationFormLessExecGradeTest(void) {
    std::cout << "--- " << __func__ << " start! ---" << std::endl;
    std::cout << std::endl;

    try {
        ShrubberyCreationForm s;
        Bureaucrat a("hoge", 138);
        std::cout << s << std::endl;
        std::cout << a << std::endl;
        a.signForm(s);
        a.executeForm(s);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "--- " << __func__ << " end! ---" << std::endl;
}

void ShrubberyCreationFormLessSignGradeTest(void) {
    std::cout << "--- " << __func__ << " start! ---" << std::endl;
    std::cout << std::endl;

    try {
        ShrubberyCreationForm s;
        Bureaucrat a("hoge", 146);
        std::cout << s << std::endl;
        std::cout << a << std::endl;
        a.signForm(s);
        a.executeForm(s);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "--- " << __func__ << " end! ---" << std::endl;
}

void RobotomyRequestFormNormalTest(void) {
    std::cout << "--- " << __func__ << " start! ---" << std::endl;
    std::cout << std::endl;

    try {
        RobotomyRequestForm r;
        Bureaucrat a("hoge", 3);
        std::cout << r << std::endl;
        std::cout << a << std::endl;
        a.signForm(r);
        a.executeForm(r);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "--- " << __func__ << " end! ---" << std::endl;
}

void RobotomyRequestFormNotSignedTest(void) {
    std::cout << "--- " << __func__ << " start! ---" << std::endl;
    std::cout << std::endl;

    try {
        RobotomyRequestForm r;
        Bureaucrat a("hoge", 3);
        std::cout << r << std::endl;
        std::cout << a << std::endl;
        a.executeForm(r);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "--- " << __func__ << " end! ---" << std::endl;
}

void RobotomyRequestFormLessExecGradeTest(void) {
    std::cout << "--- " << __func__ << " start! ---" << std::endl;
    std::cout << std::endl;

    try {
        RobotomyRequestForm r;
        Bureaucrat a("hoge", 138);
        std::cout << r << std::endl;
        std::cout << a << std::endl;
        a.signForm(r);
        a.executeForm(r);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "--- " << __func__ << " end! ---" << std::endl;
}

void RobotomyRequestFormLessSignGradeTest(void) {
    std::cout << "--- " << __func__ << " start! ---" << std::endl;
    std::cout << std::endl;

    try {
        RobotomyRequestForm r;
        Bureaucrat a("hoge", 146);
        std::cout << r << std::endl;
        std::cout << a << std::endl;
        a.signForm(r);
        a.executeForm(r);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "--- " << __func__ << " end! ---" << std::endl;
}


void PresidentialPardonFormNormalTest(void) {
    std::cout << "--- " << __func__ << " start! ---" << std::endl;
    std::cout << std::endl;

    try {
        PresidentialPardonForm r;
        Bureaucrat a("hoge", 3);
        std::cout << r << std::endl;
        std::cout << a << std::endl;
        a.signForm(r);
        a.executeForm(r);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "--- " << __func__ << " end! ---" << std::endl;
}

void PresidentialPardonFormNotSignedTest(void) {
    std::cout << "--- " << __func__ << " start! ---" << std::endl;
    std::cout << std::endl;

    try {
        PresidentialPardonForm r;
        Bureaucrat a("hoge", 3);
        std::cout << r << std::endl;
        std::cout << a << std::endl;
        a.executeForm(r);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "--- " << __func__ << " end! ---" << std::endl;
}

void PresidentialPardonFormLessExecGradeTest(void) {
    std::cout << "--- " << __func__ << " start! ---" << std::endl;
    std::cout << std::endl;

    try {
        PresidentialPardonForm r;
        Bureaucrat a("hoge", 138);
        std::cout << r << std::endl;
        std::cout << a << std::endl;
        a.signForm(r);
        a.executeForm(r);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "--- " << __func__ << " end! ---" << std::endl;
}

void PresidentialPardonFormLessSignGradeTest(void) {
    std::cout << "--- " << __func__ << " start! ---" << std::endl;
    std::cout << std::endl;

    try {
        PresidentialPardonForm r;
        Bureaucrat a("hoge", 146);
        std::cout << r << std::endl;
        std::cout << a << std::endl;
        a.signForm(r);
        a.executeForm(r);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "--- " << __func__ << " end! ---" << std::endl;
}

int main() {
    ShrubberyCreationFormNormalTest();
    ShrubberyCreationFormNotSignedTest();
    ShrubberyCreationFormLessExecGradeTest();
    ShrubberyCreationFormLessSignGradeTest();
    RobotomyRequestFormNormalTest();
    RobotomyRequestFormNotSignedTest();
    RobotomyRequestFormLessExecGradeTest();
    RobotomyRequestFormLessSignGradeTest();
    PresidentialPardonFormNormalTest();
    PresidentialPardonFormNotSignedTest();
    PresidentialPardonFormLessExecGradeTest();
    PresidentialPardonFormLessSignGradeTest();
    return 0;
}
