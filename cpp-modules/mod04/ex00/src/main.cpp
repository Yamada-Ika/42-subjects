#include <iostream>
#include <cstdlib>

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define START() std::cout << __func__ << " start!" << std::endl;
#define END() std::cout << __func__ << " end!" << std::endl;

void  NormalTest(void) {
    START();
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete i;
    delete j;

    END();
}

void  WrongTest(void) {
    START();
    const WrongAnimal* meta = new WrongAnimal();
    const WrongAnimal* i = new WrongCat();

    std::cout << "WrongCat type : " << i->getType() << " " << std::endl;
    i->makeSound();
    meta->makeSound();
    delete meta;
    delete i;
    END();
}

int main(void) {
    if (std::getenv("IYAMADA_CPP04_EX00_NORMAL") != NULL) {
        NormalTest();
    }

    if (std::getenv("IYAMADA_CPP04_EX00_WRONG") != NULL) {
        WrongTest();
    }

    return 0;
}
