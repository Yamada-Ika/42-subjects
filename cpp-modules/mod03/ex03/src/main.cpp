#include <iostream>

#include <DiamondTrap.hpp>

#define HEADER() std::cout << "\033[32mSTART : " << __func__ << "\033[0m" << std::endl

void CanonicalTest(void) {
    HEADER();

    DiamondTrap a("hoge");
    DiamondTrap b(a);
    DiamondTrap c;
    DiamondTrap d("fuga");
    c = b;
}

void HitpointTest(void) {
    HEADER();

    DiamondTrap s("hoge");
    s.takeDamage(99);
    s.attack("fuga");
    s.takeDamage(1);
    s.attack("fuga");
}

void EnergypointTest(void) {
    HEADER();

    DiamondTrap s("hoge");
    for (int i = 0; i < 50; i++) {
        s.beRepaired(1);
    }
    s.beRepaired(1);
}

void WhoAmITest(void) {
    HEADER();

    DiamondTrap s("hoge");
    s.whoAmI();
}

int main(void) {
    CanonicalTest();
    HitpointTest();
    EnergypointTest();
    WhoAmITest();
    return 0;
}
