#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

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

void ex01gradeTooHighTest(void) {
    std::cout << "--- " << __func__ << " start! ---" << std::endl;
    std::cout << std::endl;

    try {
        Form f("hoge", 0, 12);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "--- " << __func__ << " end! ---" << std::endl;
}

void ex01gradeTooLowTest() {
    std::cout << "--- " << __func__ << " start! ---" << std::endl;
    std::cout << std::endl;

    try {
        Form f("hoge", 151, 12);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "--- " << __func__ << " end! ---" << std::endl;
}

void ex01BeSignedTest() {
    std::cout << "--- " << __func__ << " start! ---" << std::endl;
    std::cout << std::endl;

    try {
        Form f("hoge form", 10, 10);
        Bureaucrat b("hoge", 10);
        f.beSigned(b);

        Form f2("hoge form", 9, 10);
        f2.beSigned(b);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "--- " << __func__ << " end! ---" << std::endl;
}

void ex01signFormTest() {
    std::cout << "--- " << __func__ << " start! ---" << std::endl;
    std::cout << std::endl;

    try {
        Form f("hoge form", 10, 10);
        Bureaucrat b("hoge", 10);
        b.signForm(f);
        b.signForm(f);

        Form f2("hoge form", 9, 10);
        b.signForm(f2);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "--- " << __func__ << " end! ---" << std::endl;
}

int main(void) {
    if (std::getenv("IYAMADA_CPP05_EX01_EX00TEST")) {
        ex00Test();
    }
    if (std::getenv("IYAMADA_CPP05_EX01_EX01GRADETOOHIGHTEST")) {
        ex01gradeTooHighTest();
    }
    if (std::getenv("IYAMADA_CPP05_EX01_EX01GRADETOOLOWTEST")) {
        ex01gradeTooLowTest();
    }
    if (std::getenv("IYAMADA_CPP05_EX01_EX01GRADETOOLOWTEST")) {
        ex01BeSignedTest();
    }
    if (std::getenv("IYAMADA_CPP05_EX01_EX01BESIGNEDTEST")) {
        ex01BeSignedTest();
    }
    if (std::getenv("IYAMADA_CPP05_EX01_EX01SIGNFORMTEST")) {
        ex01signFormTest();
    }

    return 0;
}
