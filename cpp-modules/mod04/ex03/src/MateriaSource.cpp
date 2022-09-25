#include "MateriaSource.hpp"

#include <string>

void MateriaSource::initMaterias() {
    for (int i = 0; i < kMaxSize; ++i) {
        materias_[i] = NULL;
    }
}


MateriaSource::MateriaSource(void) {
    initMaterias();
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    initMaterias();
    *this = other;
}

MateriaSource::~MateriaSource(void) {
    for (int i = 0; i < kMaxSize; ++i) {
        delete materias_[i];
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    for (int i = 0; i < kMaxSize; ++i) {
        delete this->materias_[i];
        if (other.materias_[i] == NULL) {
            this->materias_[i] = NULL;
            continue;
        }
        this->materias_[i] = other.materias_[i]->clone();
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
    if (m == NULL) return;

    for (int i = 0; i < kMaxSize; ++i) {
        if (materias_[i] == NULL) {
            materias_[i] = m;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < kMaxSize; ++i) {
        if (materias_[i] == NULL) {
            continue;
        }
        if (materias_[i]->getType() == type) {
            return materias_[i]->clone();
        }
    }
    return NULL;
}
