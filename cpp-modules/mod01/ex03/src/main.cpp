#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

#include <iostream>

int main() {
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jhon("jhon");
        jhon.attack();
        jhon.setWeapon(club);
        club.setType("some other type of club");
        jhon.attack();
    }
    return 0;
}
