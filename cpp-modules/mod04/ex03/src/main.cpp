#include <iostream>
#include <cassert>

#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void pdfTest(void) {
    IMateriaSource* src = new MateriaSource();

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
}

void cloneTest() {
    // clone test
    //   - ice
    Ice *ice = new Ice();
    AMateria *ice_clone = ice->clone();
    std::cout << "materia type : " << ice->getType() << std::endl;
    assert(ice_clone->getType() == ice->getType());
    //   - cure
    Cure *cure = new Cure();
    AMateria *cure_clone = cure->clone();
    std::cout << "materia type : " << cure->getType() << std::endl;
    assert(cure_clone->getType() == cure->getType());

    delete ice;
    delete ice_clone;
    delete cure;
    delete cure_clone;
}

void copyTest() {
    Character* bob = new Character("bob");
    Character* me = new Character("me");

    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    AMateria* tmp = src->createMateria("ice");
    bob->equip(tmp);
    bob->use(0, *me);

    ICharacter* bob2 = new Character(*bob);

    bob2->use(0, *me);

    delete bob;
    delete bob2;
    delete me;
    delete src;
}

int main(void) {
    if (std::getenv("IYAMADA_REVIE_CPP04_EX03_PDFTEST") != NULL) {
        pdfTest();
    }
    if (std::getenv("IYAMADA_REVIE_CPP04_EX03_CLONETEST") != NULL) {
        cloneTest();
    }
    if (std::getenv("IYAMADA_REVIE_CPP04_EX03_COPYTEST") != NULL) {
        copyTest();
    }

    return 0;
}
