#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

// TODO Characterみたいにdeep copyを実装すべきか
class MateriaSource : public IMateriaSource {
 private:
    static const int kMaxSize = 4;
    AMateria *materias_[kMaxSize];

    void initMaterias();

 public:
    MateriaSource();
    ~MateriaSource();
    MateriaSource(const MateriaSource& other);
    MateriaSource &operator=(const MateriaSource& other);

    void learnMateria(AMateria*);
    AMateria* createMateria(std::string const & type);
};

#endif
