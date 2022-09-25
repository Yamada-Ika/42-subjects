#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    try {
        Zombie *zombies = new Zombie[N];

        for (int i = 0; i < N; i++) {
            zombies[i].setName(name);
        }
        return zombies;
    } catch(const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        std::exit(1);
    }
}
