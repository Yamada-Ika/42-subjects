#include "Character.hpp"

void Character::initSlot() {
    for (int i = 0; i < kMaxSize; ++i) {
        slot[i] = NULL;
    }
}

Character::Character(void) : name_("") {
    initSlot();
}

Character::Character(std::string const &name) : name_(name) {
    initSlot();
}

Character::Character(Character const &other) : name_("") {
    initSlot();
    *this = other;
}

Character::~Character() {
    for (int i = 0; i < kMaxSize; ++i) {
        delete slot[i];
    }
}

Character& Character::operator=(const Character& other) {
    for (int i = 0; i < kMaxSize; ++i) {
        delete this->slot[i];
        if (other.slot[i] == NULL) {
            this->slot[i] = NULL;
            continue;
        }
        this->slot[i] = other.slot[i]->clone();
    }
    return *this;
}

std::string const & Character::getName() const {
    return name_;
}

void Character::equip(AMateria *m) {
    if (m == NULL) return;

    for (int i = 0; i < kMaxSize; ++i) {
        if (slot[i] == NULL) {
            slot[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx) {
    if (idx < 0 || kMaxSize < idx) return;

    slot[idx] = NULL;  // leak ?
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || kMaxSize < idx
        || slot[idx] == NULL) {
        return;
    }

    slot[idx]->use(target);
}
