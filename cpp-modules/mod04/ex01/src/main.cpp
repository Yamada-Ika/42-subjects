#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

# define START() std::cout << "function : " << __func__ << " start!" << std::endl;
# define END() std::cout << "function : " << __func__ << " end!" << std::endl;

void  NormalTest(void) {
    START();

    std::cout << std::endl;
    const Animal* j = new Dog();
    std::cout << std::endl;

    const Animal* i = new Cat();
    std::cout << std::endl;

    delete j;
    std::cout << std::endl;

    delete i;
    std::cout << std::endl;

    END();
}

void NormalTest2(void) {
    START();

    std::cout << std::endl;
    Animal *animals[10];
    std::cout << std::endl;

    for (int i = 0; i < 5; ++i) {
        animals[i] = new Dog();
        std::cout << std::endl;
    }
    for (int i = 5; i < 10; ++i) {
        animals[i] = new Cat();
        std::cout << std::endl;
    }

    for (int i = 0; i < 10; ++i) {
        delete animals[i];
        std::cout << std::endl;
    }

    END();
}

void  CopyTest(void) {
    START();
    Dog basic;
    std::cout << std::endl;

    {
        Dog tmp = basic;
        std::cout << std::endl;
    }
    END();
}

int main(void) {
    if (std::getenv("IYAMADA_CPP04_EX01_NORMAL") != NULL) {
        NormalTest();
    }
    if (std::getenv("IYAMADA_CPP04_EX01_NORMAL2") != NULL) {
        NormalTest2();
    }
    if (std::getenv("IYAMADA_CPP04_EX01_COPY") != NULL) {
        CopyTest();
    }

    return 0;
}
