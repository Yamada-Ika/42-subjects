#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

void normal(void) {
    Zombie *zombies;

    zombies = zombieHorde(5, "hoge");
    for (int i = 0; i < 5; i++) {
        zombies[i].announce();
    }
    delete [] zombies;
}

void badAllocate(void) {
    Zombie *zombies;

    zombies = zombieHorde(-1, "hoge");
    for (int i = 0; i < 5; i++) {
        zombies[i].announce();
    }
    delete [] zombies;
}

int main(void) {
    normal();
    badAllocate();
}
