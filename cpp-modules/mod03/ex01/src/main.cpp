#include <iostream>

#include <ClapTrap.hpp>
#include <ScavTrap.hpp>

#define HEADER() std::cout << "\033[32mSTART : " << __func__ << "\033[0m" << std::endl

void CanonicalTest(void) {
    HEADER();

    ScavTrap a("hoge");
    ScavTrap b(a);
    ScavTrap c;
    ScavTrap d("fuga");
    c = b;
}

void ConstructorAndDestructorTest(void) {
    HEADER();

    ScavTrap s("hoge");
}

void BeRepairedAndTakeDamageTest(void) {
    HEADER();

    ScavTrap s("hoge");
    s.beRepaired(100);
    s.takeDamage(100);
}

void AttackMessageTest(void) {
    HEADER();

    ScavTrap s("hoge");
    s.attack("fuga");
}

void GuardGateTest(void) {
    HEADER();

    ScavTrap s("hoge");
    s.guardGate();
}

void HitpointTest(void) {
    HEADER();

    ScavTrap s("hoge");
    s.takeDamage(99);
    s.attack("fuga");
    s.takeDamage(1);
    s.attack("fuga");
}


void EnergypointTest(void) {
    HEADER();

    ScavTrap s("hoge");
    for (int i = 0; i < 50; i++) {
        s.beRepaired(100);
    }
    s.beRepaired(100);
}

int main(void) {
    CanonicalTest();
    ConstructorAndDestructorTest();
    AttackMessageTest();
    BeRepairedAndTakeDamageTest();
    GuardGateTest();
    HitpointTest();
    EnergypointTest();
    return 0;
}
