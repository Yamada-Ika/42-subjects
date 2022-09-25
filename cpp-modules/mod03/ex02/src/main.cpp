#include <iostream>

#include <FragTrap.hpp>

#define HEADER() std::cout << "\033[32mSTART : " << __func__ << "\033[0m" << std::endl

void CanonicalTest(void) {
    HEADER();

    FragTrap a("hoge");
    FragTrap b(a);
    FragTrap c;
    FragTrap d("fuga");
    c = b;
}

void ConstructorAndDestructorTest(void) {
    HEADER();

    FragTrap s("hoge");
}

void AttackAndBeRepairedAndTakeDamageTest(void) {
    HEADER();

    FragTrap s("hoge");
    s.attack("fuga");
    s.beRepaired(100);
    s.takeDamage(100);
}

void GuardGateTest(void) {
    HEADER();

    FragTrap s("hoge");
    s.highFivesGuys();
}

void HitpointTest(void) {
    HEADER();

    FragTrap s("hoge");
    s.takeDamage(99);
    s.attack("fuga");
    s.takeDamage(1);
    s.attack("fuga");
}


void EnergypointTest(void) {
    HEADER();

    FragTrap s("hoge");
    for (int i = 0; i < 100; i++) {
        s.beRepaired(100);
    }
    s.beRepaired(100);
}


int main(void) {
    CanonicalTest();
    ConstructorAndDestructorTest();
    AttackAndBeRepairedAndTakeDamageTest();
    GuardGateTest();
    HitpointTest();
    EnergypointTest();
    return 0;
}
