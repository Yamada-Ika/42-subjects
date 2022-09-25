#include "Bureaucrat.hpp"
#include <iostream>

void gradeTooHighTest(void) {
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

void gradeTooLowTest(void) {
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

void increGradeTest(void) {
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

void decreGradeTest(void) {
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

int main() {
    if (std::getenv("IYAMADA_CPP05_EX00_GRADETOOHIGHTEST") != NULL) {
        gradeTooHighTest();
    }
    if (std::getenv("IYAMADA_CPP05_EX00_GRADETOOLOWTEST") != NULL) {
        gradeTooLowTest();
    }
    if (std::getenv("IYAMADA_CPP05_EX00_INCREGRADETEST") != NULL) {
        increGradeTest();
    }
    if (std::getenv("IYAMADA_CPP05_EX00_DECREGRADETEST") != NULL) {
        decreGradeTest();
    }
    return 0;
}
