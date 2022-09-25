#include "Zombie.hpp"

void randomChump(std::string name);
Zombie* newZombie(std::string name);

int main(void) {
    Zombie *zombie;

    zombie = newZombie("heap zombie");
    zombie->announce();
    randomChump("stack zombie");
    delete zombie;
}
